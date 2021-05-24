#include "VaccineRouter.h"
#include "../GraphViewer/graphViewer.h"
#include "../algorithms/AStar.h"
#include "../graph/GraphProcessor.h"
#include <fstream>
#include <list>

VaccineRouter::VaccineRouter()
        : vaccineLifeTime("03:00:00"),
          graph(new Graph()) {}

int VaccineRouter::getCenter(Node *node) {
    for (StorageCenter *sc: this->SCs) {
        if (*sc->getNode() == *node) {
            return 0;
        }
    }
    for (ApplicationCenter *ac: this->availableACs) {
        if (*ac->getNode() == *node) {
            return 1;
        }
    }
    return -1;
}

std::string VaccineRouter::getCenterName(Node *node) {
    for (StorageCenter *sc : this->SCs) {
        if (sc->getNode() == node) {
            return sc->getName();
        }
    }
    for (ApplicationCenter *ac : this->availableACs) {
        if (ac->getNode() == node) {
            return ac->getName();
        }
    }
    return "";
}

const std::vector<StorageCenter *> &VaccineRouter::getSCs() const { return this->SCs; }

const std::vector<ApplicationCenter *> &VaccineRouter::getSelectedACs() const { return this->selectedACs; }

const std::vector<ApplicationCenter *> &VaccineRouter::getAvailableACs() const { return this->availableACs; }

Graph *VaccineRouter::getGraph() const { return this->graph; }

void VaccineRouter::setGraph(Graph *graph) { this->graph = graph; }

void VaccineRouter::setCityName(std::string cityName) { this->cityName = std::move(cityName); }

void VaccineRouter::setVaccineLifetime(std::string lifetime) {
    this->vaccineLifeTime = Time(lifetime);
    for (StorageCenter *sc : this->SCs) {
        sc->setVaccineLifetime(this->vaccineLifeTime);
    }
}

void VaccineRouter::addStorageCenter(StorageCenter *sc) { this->SCs.push_back(sc); }

void VaccineRouter::addApplicationCenter(ApplicationCenter *ac) { this->availableACs.push_back(ac); }

void VaccineRouter::selectApplicationCenter(ApplicationCenter *ac) { this->selectedACs.push_back(ac); }

void VaccineRouter::selectMap(const std::string &mapFilename) {
    this->graph = processGraph(mapFilename, true);
    setUpSCs(mapFilename);
    setUpACS(mapFilename);
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
        auto *newSC = new StorageCenter(this->graph->findNode(id), name, vaccineLifeTime);
        addStorageCenter(newSC);
    }

    istream.close();
    return true;
}

bool VaccineRouter::setUpACS(const std::string &mapFilename) {
    std::ifstream istream("../../cityMaps/" + mapFilename + "/" + mapFilename +
                          "_ACs.txt");

    if (!istream.is_open()) {
        std::cerr << "File does not exist or could not be open.\n\n";
        return false;
    }

    unsigned int id;
    std::string name;
    while (istream >> id >> name) {
        auto *newAC = new ApplicationCenter(this->graph->findNode(id), name);
        addApplicationCenter(newAC);
    }
    istream.close();
    return true;
}

StorageCenter *VaccineRouter::findNearestSC() {
    auto cmp = [](const std::pair<StorageCenter *, double> &a,
                  const std::pair<StorageCenter *, double> &b) {
        return a.second > b.second;
    };
    std::priority_queue<std::pair<StorageCenter *, double>,
            std::vector<std::pair<StorageCenter *, double>>,
            decltype(cmp)>
            dists(cmp);

    for (ApplicationCenter *ac : this->selectedACs) {
        StorageCenter *nearestSC = findNearestSC(ac);
        double dist = nearestSC->getNode()->calculateDist(ac->getNode());
        std::pair<StorageCenter *, double> nearestSCDist(nearestSC, dist);
        dists.push(nearestSCDist);
    }

    if (dists.empty()) return nullptr;
    return dists.top().first;
}

StorageCenter *VaccineRouter::findNearestSC(ApplicationCenter *applicationCenter) {
    double minDist = DOUBLE_MAX;
    double dist = 0;
    StorageCenter *nearest = nullptr;

    Coordinates ACCoords = applicationCenter->getNode()->getCoordinates();

    for (StorageCenter *sc : this->SCs) {
        Coordinates SCCoords = sc->getNode()->getCoordinates();
        dist = SCCoords.calculateEuclideanDistance(ACCoords);
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
            startingPoint->setVisited();
            nextPoint = sc->findNextNearestAC(startingPoint);
            visited++;
        } else if (vehicle->getPathDuration(path) > this->vaccineLifeTime) {
            sc->removeAC(nextPoint);
            nextPoint = sc->findNextNearestAC(startingPoint);
        } else {
            if (!vehicle->hasEmptyPath())
                sc->setOptimalState();
        }
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

    for (ApplicationCenter *ac: this->selectedACs) {
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

void VaccineRouter::deleteDispatchedACs() {
    auto it = this->selectedACs.begin();
    while (it != this->selectedACs.end()) {
        if ((*it)->isVisited())
            it = this->selectedACs.erase(it);
        else
            it++;
    }
}

void VaccineRouter::calculateRouteSingleSCSingleAC() {
    ApplicationCenter *ac = selectedACs[0]; // single AC -> we can assume it
    // corresponds to index 0
    StorageCenter *nearestSC = findNearestSC(ac);
    Vehicle *vehicle = nearestSC->getAvailableVehicle();
    nearestSC->assignAC(ac);

    std::vector<Node *> path = AStar(graph, nearestSC->getNode(),
                                     ac->getNode());

    vehicle->setVehicleRoute(path, false); // false -> TW is not being taken into account
    // no need to handle the case in which the function returns false since that would only happen if checkTW was set

    displayVehiclesPath(this);
}

void VaccineRouter::calculateRouteSingleSCMultipleAC() {
    StorageCenter *sc = findNearestSC();
    Center *startingPoint = sc;

    for (ApplicationCenter *ac : this->selectedACs)
        sc->assignAC(ac); // single/multiple -> all selectedACs will be assign to best SC option
    Vehicle *vehicle = sc->getAvailableVehicle();
    Center *nextPoint = sc->findNextNearestAC(sc);


    while (!sc->checkACsVisited() && (nextPoint != nullptr)) {
        startingPoint->setVisited();

        std::vector<Node *> path = AStar(graph, startingPoint->getNode(),
                                         nextPoint->getNode());

        vehicle->setVehicleRoute(path, false); // false -> TW is not being taken into account
        // no need to handle the case in which the function returns false since that would only happen if checkTW was set

        startingPoint = nextPoint;
        nextPoint = sc->findNextNearestAC(startingPoint);
    }
    displayVehiclesPath(this);
}

void VaccineRouter::calculateRouteSingleSCMultipleACWithTW() {
    StorageCenter *sc = findNearestSC();
    Center *startingPoint = sc;

    for (ApplicationCenter *ac : this->selectedACs)
        sc->assignAC(ac); // single/multiple -> all selectedACs will be assign to best SC option
    Vehicle *vehicle = nullptr;
    Center *nextPoint = sc->findNextNearestAC(sc);
    std::vector<Center *> unattainableAc;


    while (!sc->checkACsVisited() && (nextPoint != nullptr)) {
        vehicle = sc->getAvailableVehicle();
        startingPoint->setVisited();

        std::vector<Node *> path = dijkstra(graph, startingPoint->getNode(), nextPoint->getNode());

        if (vehicle->setVehicleRoute(path, true)) {
            startingPoint = nextPoint;
            nextPoint = sc->findNextNearestAC(startingPoint);
        } else if (vehicle->getPathDuration(path) > this->vaccineLifeTime) {//if AC can never be reached
            sc->removeAC(nextPoint); //remove AC from assigned SC
            unattainableAc.push_back(nextPoint);
            nextPoint = sc->findNextNearestAC(startingPoint);
        } else { sc->addVehicle(); }
    }

    displayVehiclesPath(this);
    if (!unattainableAc.empty())
        std::cout << "\n\n -----------UNATTAINABLE ACs-----------\n";
    for (Center *c : unattainableAc) {
        std::cout << c->getName() << " couldn't be reached without exceeding "
                                     "vaccine's lifetime\n";
    }
}

void VaccineRouter::calculateRouteMultipleSCMultipleACWithTW() {
    std::vector<Center *> unattainableAc;

    // assign selectedACs to SCs
    for (ApplicationCenter *ac : this->selectedACs) {
        StorageCenter *sc = findNearestSC(ac);
        sc->assignAC(ac);
    }

    // iterate over SCs to calculate its optimal route -> multi-threaded function
    for (StorageCenter *sc : this->SCs) {
        if (sc->getAssignedAC().empty()) continue;
        calculateSCRoute(sc);
    }

    // handles the selectedACs that could not fit in its optimally assigned SC route
    deleteDispatchedACs();
    handleACsNotVisited();
    displayVehiclesPath(this);

    if (!unattainableAc.empty())
        std::cout << "\n\n -----------UNATTAINABLE ACs-----------\n";
    for (ApplicationCenter *ac : this->selectedACs) {
        std::cout << ac->getName() << " couldn't be reached without exceeding "
                                      "vaccine's lifetime\n";
    }

}

void VaccineRouter::outputDataResults() {
    std::cout << "\n\n----- DATA RESULTS -----\n";
    std::cout << "\n\n----- STORAGE CENTERS -----\n";
    int node = 0;

    for (StorageCenter *sc :this->SCs) {
        std::cout << sc;

        std::cout << "Path(s): \n";
        for (Vehicle *vehicle : sc->getFleet()) {
            if (vehicle->hasEmptyPath()) {
                std::cout << "There were no distributions from this Center!\n";
                break;
            }
            std::cout << "Path time duration: " << vehicle->getPathDuration() <<
                      std::endl;
            for (Node *n : vehicle->getPath()) {
                node++;
                if (getCenter(n) != -1)
                    std::cout << getCenterName(n) << " ";
                else
                    std::cout << n->getId() << " ";
            }
            std::cout << "\n";
        }
    }

    std::cout << "\n\n----- APPLICATION CENTERS -----\n";
    for (ApplicationCenter *ac : this->selectedACs) {
        std::cout << ac;
    }
}
