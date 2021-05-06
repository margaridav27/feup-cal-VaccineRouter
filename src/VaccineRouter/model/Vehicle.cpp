#include "Vehicle.h"

Vehicle::Vehicle() {}

std::queue<Node *> Vehicle::getPath() {
    return this->qPath;
}

Node *Vehicle::getNextNode() {
    Node *n = this->qPath.front();
    this->qPath.pop();
    return n;
}

void Vehicle::addToPath(Node *n) {
    this->qPath.push(n);
}

void Vehicle::setSpeed(double speed) {
    this->speed = speed;
}

bool Vehicle::operator==(const Vehicle &rhs) const {
    if (this->vPath.size() != rhs.vPath.size()) return this->speed == rhs.speed;
    for (int i = 0; i < this->vPath.size(); ++i) {
        if (this->vPath[i]->getId() != rhs.vPath[i]->getId()) return false;
    }
    return this->speed == rhs.speed;
}

