#include <algorithm>
#include <utility>
#include <vector>

#include "StorageCenter.h"

StorageCenter::StorageCenter(Node *node, std::string name) :
        node(node),
        name(std::move(name)),
        vaccinesToDeliver(-1) {}

Node *StorageCenter::getNode() const {
    return this->node;
}

const std::string &StorageCenter::getName() const {
    return this->name;
}

const std::vector<Node> &StorageCenter::getAssignedAc() const {
    return this->assignedAC;
}

unsigned int StorageCenter::getVaccinesToDeliver() const {
    return this->vaccinesToDeliver;
}

void StorageCenter::setVaccinesToDeliver(unsigned int order) {
    this->vaccinesToDeliver = order;
}

const std::vector<Vehicle*> &StorageCenter::getFleet() {
    return this->fleet;
}

void StorageCenter::addVehicle(Vehicle *vehicle) {
    this->fleet.push_back(vehicle);
}

bool StorageCenter::removeVehicle(Vehicle *vehicle) {
    auto iter = std::find(this->fleet.begin(), this->fleet.end(), vehicle);
    if (iter == this->fleet.end()) return false;
    this->fleet.erase(iter);
    return true;
}

bool StorageCenter::operator==(const StorageCenter &rhs) const {
    return this->node->getId() == rhs.getNode()->getId() &&
           name == rhs.name;
}
