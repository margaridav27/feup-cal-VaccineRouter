#include <limits>

#include "Edge.h"

<<<<<<< HEAD
=======
constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f
Edge::Edge() :
        dest(nullptr),
        weight(DOUBLE_MAX) {}

Edge::Edge(Node *dest, double weight) :
        dest(dest),
        weight(weight) {}

<<<<<<< HEAD
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
=======
double Edge::getWeight() const {
    return weight;
}

Node *Edge::getDest() const {
    return dest;
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f
}
