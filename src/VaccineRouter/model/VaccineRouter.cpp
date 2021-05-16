#include "VaccineRouter.h"
#include "../algorithms/Dijkstra.h"
#include "../graph/GraphProcessor.h"
#include "../GraphViewer/graphViewer.h"
#include <fstream>

VaccineRouter::VaccineRouter() :
        vaccineLifeTime("03:00:00") {} // comback: maybe change this default value?

VaccineRouter::VaccineRouter(Time vaccineLifeTime) :
        vaccineLifeTime(vaccineLifeTime) {}

const std::vector<StorageCenter> &VaccineRouter::getSCs() const { return this->SCs; }

const std::vector<ApplicationCenter> &VaccineRouter::getACs() const { return this->ACs; }

void VaccineRouter::selectMap(const std::string& mapFilename) {
    this->graph = processGraph(mapFilename);
    setUpSCs(mapFilename);
}

bool VaccineRouter::setUpSCs(const std::string& mapFilename) {
    std::ifstream istream("../../cityMaps/" + mapFilename + "/" + mapFilename + "_SCs.txt");
    if (!istream.is_open()) {
        std::cerr << "File does not exist or could not be open.\n\n";
        return false;
    }

    //TODO: ler o respetivo ficheiro e adicionar ao vetor

    istream.close();
    return true;
}

//TODO
void VaccineRouter::processOrders() {

}

//TODO
void VaccineRouter::checkTWOverdue() {

}

StorageCenter VaccineRouter::findNearestSC(ApplicationCenter
                                               applicationCenter) {
  double minDist = DOUBLE_MAX;
  double dist = 0;
  StorageCenter *nearest = nullptr;

  Coordinates ACCoords = applicationCenter.getNode()->getCoordinates();

  for (StorageCenter sc: this->SCs){
    Coordinates SCCoords = sc.getNode()->getCoordinates();
    dist = SCCoords.calculateEuclidianDistance(ACCoords);
    if (dist < minDist){
      minDist = dist;
      nearest = &sc;
    }
  }
  return *nearest;
}

Time VaccineRouter::getVaccineLifeTime() const { return this->vaccineLifeTime; }

void VaccineRouter::calculateRouteSingleSCSingleAC() {
  Vehicle *vehicle;
  ApplicationCenter AC = ACs[0];
  StorageCenter nearestSC = findNearestSC(AC);

  dijkstra(*graph, nearestSC.getNode(), AC.getNode(), vehicle);

  displayVehiclesPath(SCs);
}

//TODO
void VaccineRouter::calculateRouteSingleSCMultipleAC() {

}

//TODO
void VaccineRouter::calculateRouteSingleSCMultipleACWithTW() {

}

//TODO
void VaccineRouter::calculateRouteMultipleSCMultipleACWithTW() {

}

void VaccineRouter::addStorageCenter(unsigned int id) {

}

void VaccineRouter::addApplicationCenter(unsigned int id) {

}
