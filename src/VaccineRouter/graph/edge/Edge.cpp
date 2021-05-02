#include <limits>

#include "Edge.h"

Edge::Edge() :
        dest(nullptr),
        weight(DOUBLE_MAX) {}

Edge::Edge(Node *dest, double weight) :
        dest(dest),
        weight(weight) {}

Node *getOrig() const{
    return this->orig;
}

Node *getDest() const{
    return this->dest;
}

double Edge::getWeight() const {
    return this->weight;
}

Node *Edge::getDest() const {
    return this->dest;
}

double getCapacity() const{
    return this->capacity;
}
double getFlow() const{
    return this->flow;
}
double getCost() const{
    return this->cost;
}
