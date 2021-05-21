#include "VaccineRouter.h"
#include "../GraphViewer/graphViewer.h"
#include "../algorithms/Dijkstra.h"
#include "../graph/GraphProcessor.h"
#include <fstream>
#include <list>

VaccineRouter::VaccineRouter()
        : vaccineLifeTime("03:00:00"), // comback: maybe change this default value?
          graph(new Graph()) {}

VaccineRouter::VaccineRouter(Time vaccineLifeTime)
        : vaccineLifeTime(vaccineLifeTime), graph(new Graph()) {}

Graph *VaccineRouter::getGraph() const { return this->graph; }

void VaccineRouter::setGraph(Graph *graph) { this->graph = graph; }

void VaccineRouter::addStorageCenter(StorageCenter *sc) { this->SCs.push_back(sc); }

void VaccineRouter::addApplicationCenter(ApplicationCenter *ac) { this->ACs.push_back(ac); }

void VaccineRouter::selectMap(const std::string &mapFilename) {
    this->graph = processGraph(mapFilename);
    setUpSCs(mapFilename);
}

bool VaccineRouter::setUpSCs(const std::string &mapFilename) {
    std::ifstream istream("../../cityMaps/" + mapFilename + "/" + mapFilename + "_SCs.txt");

    if (!istream.is_open()) {
        std::cerr << "File does not exist or could not be open.\n\n";
        return false;
    }

    unsigned int id;
    std::string name;
    while (istream >> id >> name) {
        auto *newSC = new StorageCenter(this->graph->getNode(id), name);
        addStorageCenter(newSC);
    }

    istream.close();
    return true;
}

// TODO
void VaccineRouter::processOrders() {}

Time VaccineRouter::getVaccineLifeTime() const { return this->vaccineLifeTime; }

// ----------------------------------------------------------------------------------------------

// finds nearest SC considering all ACs
StorageCenter *VaccineRouter::findNearestSC() {
    auto cmp = [](const std::pair<StorageCenter *, double> &a,
                  const std::pair<StorageCenter *, double> &b) {
        return a.second > b.second;
    };
    std::priority_queue<std::pair<StorageCenter *, double>,
            std::vector<std::pair<StorageCenter *, double>>,
            decltype(cmp)>
            dists(cmp);

    for (ApplicationCenter *ac : this->ACs) {
        StorageCenter *nearestSC = findNearestSC(ac);
        double dist = nearestSC->getNode()->calculateDist(ac->getNode());
        std::pair<StorageCenter *, double> nearestSCDist(nearestSC, dist);
        dists.push(nearestSCDist);
    }

    if (dists.empty()) return nullptr;
    return dists.top().first;
}

// does not take into account whether the SC is in optimal state or not -> will return always the same if given the same AC
StorageCenter *VaccineRouter::findNearestSC(ApplicationCenter *applicationCenter) {
    double minDist = DOUBLE_MAX;
    double dist = 0;
    auto *nearest = new StorageCenter();

    Coordinates ACCoords = applicationCenter->getNode()->getCoordinates();

    for (StorageCenter *sc : this->SCs) {
        Coordinates SCCoords = sc->getNode()->getCoordinates();
        dist = SCCoords.calculateEuclidianDistance(ACCoords);
        if (dist < minDist) {
            minDist = dist;
            nearest = sc;
        }
    }

    return nearest;
}

bool VaccineRouter::calculateSCRoute(StorageCenter *sc) {
    Center *startingPoint = sc;
    Center *nextPoint = sc->findNextNearestAC(sc);
    Vehicle *vehicle = sc->getAvailableVehicle();
    int visited = 0;

    while (!sc->isOptimalState() && nextPoint != nullptr) {
        startingPoint->setVisited();

        std::vector<Node *> path = dijkstra(graph, startingPoint->getNode(), nextPoint->getNode());

        if (vehicle->setVehicleRoute(path, true)) {
            startingPoint = nextPoint;
            nextPoint = sc->findNextNearestAC(startingPoint);
            visited++;
        } else sc->setOptimalState();
    }

    return (visited == sc->getAssignedAC().size());
}

void VaccineRouter::handleACsNotVisited() {
    auto cmp = [](const std::pair<StorageCenter *, double> &a,
                  const std::pair<StorageCenter *, double> &b) {
        return a.second < b.second;
    };

    bool allocatedAC = false;
    StorageCenter *viableSC;

    for (ApplicationCenter *ac: this->ACs) {
        std::priority_queue<std::pair<StorageCenter *, double>,
                std::vector<std::pair<StorageCenter *, double>>,
                decltype(cmp)>
                viableNextSCOptions(cmp);

        // this step will generate a priority queue containing the viable options,
        // ordered by the distance to the AC being handled in the current iteration
        for (StorageCenter *sc: this->SCs) {
            if (!sc->isOptimalState()) { // if a SC is not in optimal state, maybe the AC can fit in its route
                double dist = sc->getNode()->calculateDist(ac->getNode());
                viableNextSCOptions.push(std::pair<StorageCenter *, double>(sc, dist));
            }
        }

        do {
            viableSC = viableNextSCOptions.top().first;
            std::vector<Node *> originalPath = viableSC->getAvailableVehicle()->getPath();
            viableSC->assignAC(ac);

            // computes the route, now with the newly assigned AC, to check if it fits
            allocatedAC = calculateSCRoute(viableSC);

            if (allocatedAC) break;

            // in case the AC could not be allocated, one needs to reset originalPath and cancel the assignment
            viableSC->reset();
            viableSC->resetPath(originalPath);

            // tries again with the next viable option in the priority queue
            viableNextSCOptions.pop();
        } while (!viableNextSCOptions.empty());

        // has not been allocated yet but there are no more SCs to try
        if (viableNextSCOptions.empty() && !allocatedAC) {
            viableSC = findNearestSC(ac); // viableSC is now the SC to which the AC was originally assigned
            viableSC->addVehicle();
            calculateSCRoute(viableSC);
        }

        allocatedAC = false;
    }
}

// ----------------------------------------------------------------------------------------------

void VaccineRouter::calculateRouteSingleSCSingleAC() {
    ApplicationCenter *AC = ACs[0]; // single AC -> we can assume it corresponds to index 0
    StorageCenter *nearestSC = findNearestSC(AC);
    Vehicle *vehicle = nearestSC->getAvailableVehicle();

    std::vector<Node *> path = dijkstra(graph, nearestSC->getNode(), AC->getNode());

    vehicle->setVehicleRoute(path, false); // false -> TW is not being taken into account
    // no need to handle the case in which the function returns false since that would only happen if checkTW was set

    displayVehiclesPath(SCs);
}

void VaccineRouter::calculateRouteSingleSCMultipleAC() {
    StorageCenter *sc = findNearestSC();
    Center *nextPoint = sc->findNextNearestAC(sc);
    Center *startingPoint = sc;

    for (ApplicationCenter *ac : this->ACs)
        sc->assignAC(ac); // single/multiple -> all ACs will be assign to best SC option
    Vehicle *vehicle = sc->getAvailableVehicle();

    while (!sc->checkACsVisited() && (nextPoint != nullptr)) {
        startingPoint->setVisited();

        std::vector<Node *> path = dijkstra(graph, startingPoint->getNode(), nextPoint->getNode());

        vehicle->setVehicleRoute(path, false); // false -> TW is not being taken into account
        // no need to handle the case in which the function returns false since that would only happen if checkTW was set

        startingPoint = nextPoint;
        nextPoint = sc->findNextNearestAC(startingPoint);
    }

    displayVehiclesPath(SCs);
}

void VaccineRouter::calculateRouteSingleSCMultipleACWithTW() {
    StorageCenter *sc = findNearestSC();
    Center *nextPoint = sc->findNextNearestAC(sc);
    Center *startingPoint = sc;

    for (ApplicationCenter *ac : this->ACs)
        sc->assignAC(ac); // single/multiple -> all ACs will be assign to best SC option
    Vehicle *vehicle = nullptr;

    while (!sc->checkACsVisited() && (nextPoint != nullptr)) {
        vehicle = sc->getAvailableVehicle();
        startingPoint->setVisited();

        std::vector<Node *> path = dijkstra(graph, startingPoint->getNode(), nextPoint->getNode());

        if (vehicle->setVehicleRoute(path, true)) {
            startingPoint = nextPoint;
            nextPoint = sc->findNextNearestAC(startingPoint);
        } else sc->addVehicle();
    }
    displayVehiclesPath(SCs);
}

void VaccineRouter::calculateRouteMultipleSCMultipleACWithTW() {
    std::list<std::thread *> threadList;
    // assign ACs to SCs
    for (ApplicationCenter *ac : this->ACs) {
        StorageCenter *sc = findNearestSC(ac);
        sc->assignAC(ac);
    }

    // iterate over SCs to calculate its optimal route -> multi-threaded function
    for (StorageCenter *sc : this->SCs) {
        if (sc->getAssignedAC().empty()) continue;
        std::thread thread([&]() {
            calculateSCRoute(sc);
            threadList.push_back(&thread);
        });
    }
    while (!threadList.empty()) {
        threadList.back()->join();
        threadList.pop_back();
    }

    // handles the ACs that could not fit in its optimally assigned SC route
    handleACsNotVisited();
}
