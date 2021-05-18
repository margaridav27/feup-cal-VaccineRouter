#include <fstream>
#include "VaccineRouter.h"
#include "../algorithms/Dijkstra.h"
#include "../graph/GraphProcessor.h"
#include "../GraphViewer/graphViewer.h"
#include <fstream>

VaccineRouter::VaccineRouter() :
        vaccineLifeTime("03:00:00"),  // comback: maybe change this default value?
        graph(new Graph()) {}

VaccineRouter::VaccineRouter(Time vaccineLifeTime) :
        vaccineLifeTime(vaccineLifeTime),
        graph(new Graph()) {}

Graph *VaccineRouter::getGraph() const { return this->graph; }

void VaccineRouter::setGraph(Graph *graph) { this->graph = graph; }

const std::vector<StorageCenter *> &VaccineRouter::getSCs() const { return this->SCs; }

const std::vector<ApplicationCenter *> &VaccineRouter::getACs() const { return this->ACs; }

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

//TODO
void VaccineRouter::processOrders() {

}

//TODO
bool VaccineRouter::checkTWOverdue(Vehicle *vehicle) const{

}

StorageCenter *VaccineRouter::findNearestSC(ApplicationCenter *applicationCenter) {
    double minDist = DOUBLE_MAX;
    double dist = 0;
    auto *nearest = new StorageCenter();

    Coordinates ACCoords = applicationCenter->getNode()->getCoordinates();

    for (StorageCenter *sc: this->SCs) {
        Coordinates SCCoords = sc->getNode()->getCoordinates();
        dist = SCCoords.calculateEuclidianDistance(ACCoords);
        if (dist < minDist) {
            minDist = dist;
            nearest = sc;
        }
    }

    return nearest;
}

StorageCenter *VaccineRouter::findNearestSC() {
    auto cmp = [](const std::pair<StorageCenter *, double> &a, const std::pair<StorageCenter *, double> &b) {
        return a.second > b.second;
    };
    std::priority_queue<std::pair<StorageCenter *, double>,
            std::vector<std::pair<StorageCenter *, double>>,
            decltype(cmp)> dists(cmp);

    for (ApplicationCenter *ac : this->ACs) {
        StorageCenter *nearestSC = findNearestSC(ac);
        double dist = nearestSC->getNode()->calculateDist(ac->getNode());
        std::pair<StorageCenter *, double> nearestSCDist(nearestSC, dist);
        dists.push(nearestSCDist);
    }

    return dists.top().first;
}

ApplicationCenter *VaccineRouter::findNextNearestAC(Center *startingPoint) {
    auto cmp = [](const std::pair<ApplicationCenter *, double> &a, const std::pair<ApplicationCenter *, double> &b) {
        return a.second < b.second;
    };
    std::priority_queue<std::pair<ApplicationCenter *, double>,
            std::vector<std::pair<ApplicationCenter *, double>>,
            decltype(cmp)> dists(cmp);

    for (ApplicationCenter *ac : this->ACs) {
        if (!ac->isVisited() && (ac != startingPoint)) {
            double dist = ac->getNode()->calculateDist(ac->getNode());
            std::pair<ApplicationCenter *, double> nearestACDist(ac, dist);
            dists.push(nearestACDist);
        }
    }

    if (dists.empty()) return nullptr;
    return dists.top().first;
}

bool VaccineRouter::checkACsVisited() {
    return std::all_of(ACs.begin(),
                       ACs.end(),
                       [](const ApplicationCenter *ac) { return ac->isVisited(); });
}

Time VaccineRouter::getVaccineLifeTime() const { return this->vaccineLifeTime; }

void VaccineRouter::calculateRouteSingleSCSingleAC() {
    auto *vehicle = new Vehicle(this->vaccineLifeTime);
    ApplicationCenter *AC = ACs[0];
    StorageCenter *nearestSC = findNearestSC(AC);

    std::vector<Node *> path = dijkstra(graph, nearestSC->getNode(), AC->getNode
                                                                  ());
    vehicle->setVehicleRoute(path, false);

    displayVehiclesPath(SCs);
}

void VaccineRouter::calculateRouteSingleSCMultipleAC() {
    auto *vehicle = new Vehicle(this->vaccineLifeTime);
    Center *startingPoint = findNearestSC();
    Center *nextPoint = findNextNearestAC(startingPoint);

  while(!checkACsVisited() && (nextPoint != nullptr)){
    startingPoint->setVisited();
    std::vector<Node *> path = dijkstra(graph, startingPoint->getNode(),
                            nextPoint->getNode());
    vehicle->setVehicleRoute(path, false);
    startingPoint = nextPoint;
    nextPoint = findNextNearestAC(startingPoint);
  }

  displayVehiclesPath(SCs);
}

//TODO
void VaccineRouter::calculateRouteSingleSCMultipleACWithTW() {


}

//TODO
void VaccineRouter::calculateRouteMultipleSCMultipleACWithTW() {

}
