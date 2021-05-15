#include "Vehicle.h"

Vehicle::Vehicle() {}

std::stack<Node *> Vehicle::getPath() {
    return this->qPath;
}

Node *Vehicle::getNextNode() {
    Node *n = this->qPath.top();
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

void Vehicle::setVehicleRouteDest(Graph graph, Node *dest) {
  Node *aux = graph.findNode(dest);

  while (aux != nullptr) {
    this->addToPath(aux);
    aux = aux->getPath();
  }
}

void Vehicle::setVehicleRouteOrig(Graph graph, Node *orig) {
  Node *aux = graph.findNode(orig);

  while (aux != nullptr) {
    this->addToPath(aux);
    aux = aux->getPath();
  }
}
