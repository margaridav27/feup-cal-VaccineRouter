#include "Vehicle.h"
#include <algorithm>

Vehicle::Vehicle() {
  this->vPath = std::vector<Node *>();
  this->qPath = std::stack<Node *>();
  this->pathDuration = Time(0,0,0);
}

std::stack<Node *> Vehicle::getPath() { return this->qPath; }

Node *Vehicle::getNextNode() {
  if (this->qPath.empty())
    return nullptr;
  Node *n = this->qPath.top();
  this->qPath.pop();
  return n;
}

Time Vehicle::getPathDuration() {
  if (this->hasEmptyPath())
    return {0, 0, 0};

  Time duration(0,0,0);

  for (auto it = vPath.begin(); it != vPath.end(); it++){
    Node* node1 = *it;
    Node* node2 = *it++;
    Coordinates coord1 = node1->getCoordinates();
    Coordinates coord2 = node2->getCoordinates();
    double dist = coord2.calculateEuclidianDistance(coord2);
    duration += Time(dist * this->speed);
  }
  return duration;
}

bool Vehicle::addToPath(Node *n) {
  if (hasEmptyPath()){
    this->qPath.push(n);
    return true;
  }

  Coordinates c1 = this->vPath[this->vPath.size()-1]->getCoordinates();
  Coordinates c2 = n->getCoordinates();
  double dist = c1.calculateEuclidianDistance(c2);

  Time checkOverdueTime = this->pathDuration + Time(dist * speed);
  this->pathDuration += Time(dist * speed);
  reu
}

void Vehicle::setSpeed(double speed) { this->speed = speed; }

void Vehicle::setVehicleRoute(Graph graph, Node *dest) {
  int index = this->vPath.size();
  Node *aux = graph.findNode(dest);

  while (aux != nullptr) {
    if (std::find(this->vPath.begin(), this->vPath.end(), aux) !=
        this->vPath.end()) {
      aux = aux->getPath();
      continue;
    }
    this->vPath.insert(this->vPath.begin() + index, aux);
    this->addToPath(aux);
    aux = aux->getPath();
  }
}

bool Vehicle::hasEmptyPath() const{
  return (this->vPath.empty());
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
