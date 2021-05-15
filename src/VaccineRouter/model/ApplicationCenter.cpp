#include "ApplicationCenter.h"

#include <utility>

ApplicationCenter::ApplicationCenter(unsigned int locationNodeId, std::string name) :
        locationNodeID(locationNodeId),
        name(name),
        vaccinesToReceive(0) {}

unsigned int ApplicationCenter::getLocationNodeId() const {
    return this->locationNodeID;
}

const std::string &ApplicationCenter::getName() const {
    return this->name;
}

unsigned int ApplicationCenter::getVaccinesToReceive() const {
    return this->vaccinesToReceive;
}

void ApplicationCenter::setVaccinesToReceive(unsigned int order) {
    this->vaccinesToReceive = order;
}

bool ApplicationCenter::operator==(const ApplicationCenter &rhs) const {
    return locationNodeID == rhs.locationNodeID &&
           name == rhs.name;
}
