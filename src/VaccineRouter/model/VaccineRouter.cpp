#include <fstream>
#include "VaccineRouter.h"
#include "../graph/GraphProcessor.h"


VaccineRouter::VaccineRouter() :
        vaccineLifeTime("03:00:00") {} // comback: maybe change this default value?

VaccineRouter::VaccineRouter(Time vaccineLifeTime) :
        vaccineLifeTime(vaccineLifeTime) {}

const std::vector<StorageCenter> &VaccineRouter::getSCs() const { return this->SCs; }

const std::vector<ApplicationCenter> &VaccineRouter::getACs() const { return this->ACs; }

void VaccineRouter::addStorageCenter(const StorageCenter& sc) { this->SCs.push_back(sc); }

void VaccineRouter::addApplicationCenter(const ApplicationCenter& ac) { this->ACs.push_back(ac); }

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

    unsigned int id;
    std::string name;
    while(istream >> id >> name) {
        StorageCenter newSC(id, name);
        addStorageCenter(newSC);
    }

    istream.close();
    return true;
}

//TODO
void VaccineRouter::processOrders() {

}

//TODO
void VaccineRouter::checkTWOverdue() {

}

//TODO
void VaccineRouter::findNearestSC() {

}

//TODO
void VaccineRouter::findSC() {

}

//TODO
Time VaccineRouter::getVaccineLifeTime() const {

}

//TODO
void VaccineRouter::calculateRouteSingleSCSingleAC() {

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








