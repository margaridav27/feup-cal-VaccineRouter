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
    this->fleet.push_back(new Vehicle(Time(8, 0, 0)));
    this->optimalState = false;
}

void StorageCenter::addVehicle() {
    this->fleet.push_back(new Vehicle(Time(8, 0, 0)));
}

bool StorageCenter::removeVehicle(Vehicle *vehicle) {
    auto iter = std::find(this->fleet.begin(), this->fleet.end(), vehicle);
    if (iter == this->fleet.end())
        return false;
    this->fleet.erase(iter);
    return true;
}

const std::vector<Vehicle *> &StorageCenter::getFleet() { return this->fleet; }

Vehicle *StorageCenter::getAvailableVehicle() const {
    return this->fleet[this->fleet.size() - 1];
}

const std::vector<ApplicationCenter *> &StorageCenter::getAssignedAC() const { return this->assignedAC; }

void StorageCenter::assignAC(ApplicationCenter *ac) { this->assignedAC.push_back(ac); }

bool StorageCenter::checkACsVisited() {
    return std::all_of(assignedAC.begin(), assignedAC.end(), [](const ApplicationCenter *ac) {
        return ac->isVisited();
    });
}

unsigned int StorageCenter::getVaccinesToDeliver() const { return this->vaccinesToDeliver; }

void StorageCenter::setVaccinesToDeliver(unsigned int order) { this->vaccinesToDeliver = order; }

bool StorageCenter::isOptimalState() const { return this->optimalState; }

void StorageCenter::setOptimalState() { this->optimalState = true; }

void StorageCenter::unsetOptimalState() { this->optimalState = false; }

void StorageCenter::resetPath(std::vector<Node *> originalPath) const {
    this->getAvailableVehicle()->setPath(std::move(originalPath));
}

void StorageCenter::reset() {
    this->unsetOptimalState();
    this->assignedAC.pop_back();
}

ApplicationCenter *StorageCenter::findNextNearestAC(Center *startingPoint) const {
    auto cmp = [](const std::pair<ApplicationCenter *, double> &a,
                  const std::pair<ApplicationCenter *, double> &b) {
        return a.second < b.second;
    };
    std::priority_queue<std::pair<ApplicationCenter *, double>,
            std::vector<std::pair<ApplicationCenter *, double>>,
            decltype(cmp)>
            dists(cmp);

    for (ApplicationCenter *ac : this->getAssignedAC()) {
        if (!ac->isVisited() && (ac != startingPoint)) {
            double dist = ac->getNode()->calculateDist(ac->getNode());
            std::pair<ApplicationCenter *, double> nearestACDist(ac, dist);
            dists.push(nearestACDist);
        }
    }

    if (dists.empty()) return nullptr;
    return dists.top().first;
}

bool StorageCenter::operator==(const StorageCenter *rhs) const {
    return this->node->getId() == rhs->getNode()->getId() &&
           name == rhs->getName();
}
