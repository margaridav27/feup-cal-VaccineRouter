#include "Vehicle.h"
#include <algorithm>

Vehicle::Vehicle(Time maxPathDuration) {
    this->vPath = std::vector<Node *>();
    this->qPath = std::stack<Node *>();
    this->pathDuration = Time(0, 0, 0);
    this->maxPathDuration = maxPathDuration;
}

std::vector<Node *> Vehicle::getPath() { return this->vPath; }

Node *Vehicle::getNextNode() {
    if (this->qPath.empty())
        return nullptr;
    Node *n = this->qPath.top();
    this->qPath.pop();
    return n;
}

Time Vehicle::getPathDuration(std::vector<Node *> path) const {
    Time duration(0, 0, 0);

    for (int i = 0; i < path.size() - 1; ++i) {
        Node *node1 = path[i];
        Node *node2 = path[i + 1];
        Coordinates coord1 = node1->getCoordinates();
        Coordinates coord2 = node2->getCoordinates();
        double dist = coord1.calculateEuclidianDistance(coord2);
        duration += Time(dist / this->speed);
    }
    return duration;
}

void Vehicle::addToPath(std::vector<Node *> path) {
    if (hasEmptyPath())
        this->vPath.insert(this->vPath.end(), path.begin(), path.end());
    else
        this->vPath.insert(this->vPath.end(), path.begin() + 1, path.end());

}

void Vehicle::setSpeed(double speed) { this->speed = speed; }

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

bool Vehicle::hasEmptyPath() const { return (this->vPath.empty()); }

bool Vehicle::operator==(const Vehicle &rhs) const {
    if (this->vPath.size() != rhs.vPath.size())
        return this->speed == rhs.speed;
    for (int i = 0; i < this->vPath.size(); ++i) {
        if (this->vPath[i]->getId() != rhs.vPath[i]->getId())
            return false;
    }
    return this->speed == rhs.speed;
}

void Vehicle::setPath(std::vector<Node *> oldPath) {
    this->vPath.swap(oldPath);
}
