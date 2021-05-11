#include "VaccineRouter.h"


VaccineRouter::VaccineRouter() :
        vaccineLifeTime("03:00:00") {} // comback: maybe change this default value?

VaccineRouter::VaccineRouter(Time vaccineLifeTime) :
        vaccineLifeTime(vaccineLifeTime) {}

const std::hash<std::string> &VaccineRouter::getMapsHashName() const {
    return this->mapsHashName;
}

//TODO
void VaccineRouter::loadMap(std::string MapFileName) {

}

//TODO
void VaccineRouter::setUpGraph(std::string MapFileName) {

}

//TODO
void VaccineRouter::selectGraph(std::string MapFileName) {

}

//TODO
void VaccineRouter::processGraph() {

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




