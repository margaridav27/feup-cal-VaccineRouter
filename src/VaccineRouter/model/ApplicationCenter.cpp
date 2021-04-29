#include "ApplicationCenter.h"

ApplicationCenter::ApplicationCenter(unsigned int locationNodeId) :
        locationNodeID(locationNodeId),
        vaccinesToReceive(0) {}

unsigned int ApplicationCenter::getLocationNodeId() const {
    return this->locationNodeID;
}

unsigned int ApplicationCenter::getVaccinesToReceive() const {
    return this->vaccinesToReceive;
}

void ApplicationCenter::setVaccinesToReceive(unsigned int order) {
    this->vaccinesToReceive = order;
}
