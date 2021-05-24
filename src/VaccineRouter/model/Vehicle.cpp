#include "Vehicle.h"


Vehicle::Vehicle() :
        vPath(std::vector<Node *>()),
        pathDuration(Time(0, 0, 0)),
        maxPathDuration(Time(0, 0, 0)) {}

Vehicle::Vehicle(Time maxPathDuration) :
        vPath(std::vector<Node *>()),
        pathDuration(Time(0, 0, 0)),
        maxPathDuration(maxPathDuration) {}

std::vector<Node *> Vehicle::getPath() { return this->vPath; }

void Vehicle::setPath(std::vector<Node *> oldPath) {
    this->vPath.swap(oldPath);
}

void Vehicle::setMaxPathDuration(const Time &maxPathDuration) {
    Vehicle::maxPathDuration = maxPathDuration;
}

Time Vehicle::getPathDuration(std::vector<Node *> path) const {
    Time duration(0, 0, 0);

    for (int i = 0; i < path.size() - 1; ++i) {
        Node *node1 = path[i];
        Node *node2 = path[i + 1];
        Coordinates coord1 = node1->getCoordinates();
        Coordinates coord2 = node2->getCoordinates();
        double dist = coord1.calculateEuclideanDistance(coord2);
        duration += Time((dist / 100) / this->speed);
    }
    return duration;
}

Time *Vehicle::getPathDuration() { return &this->pathDuration; }

void Vehicle::addToPath(std::vector<Node *> path) {
    if (hasEmptyPath())
        this->vPath.insert(this->vPath.end(), path.begin(), path.end());
    else
        this->vPath.insert(this->vPath.end(), path.begin() + 1, path.end());

}

bool Vehicle::hasEmptyPath() const { return (this->vPath.empty()); }

bool Vehicle::setVehicleRoute(const std::vector<Node *> &path, bool checkTW) {
    Time duration = getPathDuration(path);
    if (checkTW) {
        if (this->pathDuration + duration > this->maxPathDuration) {
            return false;
        }
    }
    this->addToPath(path);
    this->pathDuration += duration;
    return true;
}

bool Vehicle::operator==(const Vehicle &rhs) const {
    if (this->vPath.size() != rhs.vPath.size())
        return this->speed == rhs.speed;
    for (int i = 0; i < this->vPath.size(); ++i) {
        if (this->vPath[i]->getId() != rhs.vPath[i]->getId())
            return false;
    }
    return this->speed == rhs.speed;
}
