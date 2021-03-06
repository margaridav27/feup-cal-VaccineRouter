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

Node *Edge::getOrig() const { return this->orig; }

Node *Edge::getDest() { return this->dest; }

double Edge::getWeight() const { return this->weight; }

double Edge::getCost() const { return this->cost; }
