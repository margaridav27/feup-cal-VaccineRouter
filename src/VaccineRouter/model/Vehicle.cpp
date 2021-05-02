#include "Vehicle.h"

std::queue<Node *> Vehicle::getPath(){
    return this->qPath;
}

Node *Vehicle::getNextNode(){
  Node *n  = this->qPath.front();
  this->qPath.pop();
  return n;
}

void Vehicle::addToPath(Node *n){
  this->qPath.push(n);
}

void Vehicle::setSpeed(double speed){
  this->speed = speed;
}
