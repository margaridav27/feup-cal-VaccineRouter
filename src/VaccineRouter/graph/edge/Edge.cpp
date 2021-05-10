#include <limits>

#include "Edge.h"


Edge::Edge() :
        orig(nullptr),
        dest(nullptr),
        weight(DOUBLE_MAX) {}

Edge::Edge(Node *source, Node *dest, double weight) :
        orig(source),
        dest(dest),
        weight(weight) {}

Node *Edge::getOrig() const {
    return this->orig;
}

Node *Edge::getDest() const {
    return this->dest;
}

double Edge::getWeight() const {
    return this->weight;
}

double Edge::getCapacity() const {
    return this->capacity;
}

double Edge::getFlow() const {
    return this->flow;
}

double Edge::getCost() const {
    return this->cost;
}
