#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

#include "StorageCenter.h"

StorageCenter::StorageCenter() : Center() {
    this->vaccinesToDeliver = 0;
    this->fleet.push_back(new Vehicle(Time(25, 0, 0)));
    this->optimalState = false;
}

StorageCenter::StorageCenter(Node *Node, const std::string &name)
        : Center(Node, name) {
    this->vaccinesToDeliver = 0;
    this->fleet.push_back(new Vehicle(Time(25, 0, 0)));
    this->optimalState = false;
}

const std::vector<ApplicationCenter *> &StorageCenter::getAssignedAc() const { return this->assignedAC; }

unsigned int StorageCenter::getVaccinesToDeliver() const {
    return this->vaccinesToDeliver;
}

void StorageCenter::setVaccinesToDeliver(unsigned int order) {
    this->vaccinesToDeliver = order;
}

const std::vector<Vehicle *> &StorageCenter::getFleet() { return this->fleet; }

void StorageCenter::assignAC(ApplicationCenter *ac) { this->assignedAC.push_back(ac); }

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

bool StorageCenter::isOptimalState() const { return this->optimalState; }

void StorageCenter::setOptimalState() { this->optimalState = true; }

void StorageCenter::unsetOptimalState() { this->optimalState = false; }

bool StorageCenter::checkACsVisited() {
    return std::all_of(assignedAC.begin(), assignedAC.end(), [](const ApplicationCenter *ac) {
        return ac->isVisited();
    });
}

bool StorageCenter::operator==(const StorageCenter *rhs) const {
    return this->node->getId() == rhs->getNode()->getId() &&
           name == rhs->getName();
}

Vehicle *StorageCenter::getAvailableVehicle() const {
    return this->fleet[this->fleet.size() - 1];
}

ApplicationCenter *StorageCenter::findNextNearestAC(Center *startingPoint) {
    auto cmp = [](const std::pair<ApplicationCenter *, double> &a,
                  const std::pair<ApplicationCenter *, double> &b) {
        return a.second < b.second;
    };
    std::priority_queue<std::pair<ApplicationCenter *, double>,
            std::vector<std::pair<ApplicationCenter *, double>>,
            decltype(cmp)>
            dists(cmp);

    for (ApplicationCenter *ac : this->assignedAC) {
        if (!ac->isVisited() && (ac != startingPoint)) {
            double dist = ac->getNode()->calculateDist(ac->getNode());
            std::pair<ApplicationCenter *, double> nearestACDist(ac, dist);
            dists.push(nearestACDist);
        }
    }
}

void StorageCenter::resetPath(std::vector<Node *> oldPath) {
    this->getAvailableVehicle()->setPath(oldPath);

}

void StorageCenter::reset() {
    this->unsetOptimalState();
    this->assignedAC.pop_back();
}

