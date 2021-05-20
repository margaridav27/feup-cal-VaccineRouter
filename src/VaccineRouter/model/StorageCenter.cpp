#include <algorithm>
#include <utility>
#include <vector>

#include "StorageCenter.h"

StorageCenter::StorageCenter() : Center() {
  this->vaccinesToDeliver = 0;
  this->fleet.push_back(new Vehicle(Time(25, 0, 0)));
}

StorageCenter::StorageCenter(Node *Node, const std::string &name)
    : Center(Node, name) {
  this->vaccinesToDeliver = 0;
  this->fleet.push_back(new Vehicle(Time(25, 0, 0)));
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

const std::vector<Vehicle *> &StorageCenter::getFleet() { return this->fleet; }

void StorageCenter::addVehicle() {
  this->fleet.push_back(new Vehicle(Time(3, 0, 0)));
}

bool StorageCenter::removeVehicle(Vehicle *vehicle) {
  auto iter = std::find(this->fleet.begin(), this->fleet.end(), vehicle);
  if (iter == this->fleet.end())
    return false;
  this->fleet.erase(iter);
  return true;
}

bool StorageCenter::operator==(const StorageCenter *rhs) const {
  return this->node->getId() == rhs->getNode()->getId() &&
         name == rhs->getName();
}
Vehicle *StorageCenter::getAvailableVehicle() const {
  return this->fleet[this->fleet.size() - 1];
}
