#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#include "StorageCenter.h"

StorageCenter::StorageCenter(Time vaccineLifeTime) : Center() {
    this->vaccinesToDeliver = 0;
    this->fleet.push_back(new Vehicle());
    this->optimalState = false;
    this->vaccineLifeTime = vaccineLifeTime;
}

StorageCenter::StorageCenter(Node *Node, const std::string &name, Time
vaccineLifeTime = Time(3, 0, 0)) : Center(Node, name) {
    this->vaccinesToDeliver = 0;
    this->fleet.push_back(new Vehicle());
    this->optimalState = false;
    this->vaccineLifeTime = vaccineLifeTime;
}

const std::vector<Vehicle *> &StorageCenter::getFleet() { return this->fleet; }

void StorageCenter::addVehicle() { this->fleet.push_back(new Vehicle(vaccineLifeTime)); }

Vehicle *StorageCenter::getAvailableVehicle() const { return this->fleet[this->fleet.size() - 1]; }

const std::vector<ApplicationCenter *> &StorageCenter::getAssignedAC() const { return this->assignedAC; }

void StorageCenter::assignAC(ApplicationCenter *ac) {
    this->assignedAC.push_back(ac);
    this->addVaccinesToDeliver(ac->getVaccinesToReceive());
}

void StorageCenter::removeAC(Center *c) {
    for (ApplicationCenter *ac : this->assignedAC) {
        if (ac->getNode() == c->getNode())
            this->assignedAC.erase(std::find(this->assignedAC.begin(),
                                             this->assignedAC.end(), ac));
    }
}

bool StorageCenter::checkACsVisited() {
    return std::all_of(
            assignedAC.begin(), assignedAC.end(),
            [](const ApplicationCenter *ac) { return ac->isVisited(); });
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
            double dist = startingPoint->getNode()->calculateDist(ac->getNode());
            std::pair<ApplicationCenter *, double> nearestACDist(ac, dist);
            dists.push(nearestACDist);
        }
    }

    if (dists.empty())
        return nullptr;
    return dists.top().first;
}

void StorageCenter::setVaccineLifetime(Time vaccineLifetime) {
    this->vaccineLifeTime = vaccineLifetime;

    for (Vehicle *vehicle : this->fleet) {
        vehicle->setMaxPathDuration(vaccineLifetime);
    }
}

unsigned int StorageCenter::getVaccinesToDeliver() const { return this->vaccinesToDeliver; }

void StorageCenter::addVaccinesToDeliver(unsigned int order) { this->vaccinesToDeliver += order; }

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

bool StorageCenter::operator==(const StorageCenter *rhs) const {
    return this->node->getId() == rhs->getNode()->getId() &&
           name == rhs->getName();
}

std::ostream &operator<<(std::ostream &out, StorageCenter *sc) {
    out << "---------------------------------------------\n";
    out << sc->getName() << std::endl
        << "Vaccines assigned to deliver: " << sc->getVaccinesToDeliver() <<
        std::endl;

    if (!sc->getAssignedAC().empty()) {
        out << "\n Assigned Application centers:\n";
        for (ApplicationCenter *ac : sc->getAssignedAC()) {
            out << "id: " << ac->getNode()->getId() << "  name: " << ac->getName()
                << " - vaccines : " << ac->getVaccinesToReceive() << std::endl;
        }
    }
}
