#include <limits>

#include "Edge.h"

constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

Edge::Edge() :
        dest(nullptr),
        weight(DOUBLE_MAX) {}

Edge::Edge(Node *dest, double weight) :
        dest(dest),
        weight(weight) {}

double Edge::getWeight() const {
    return weight;
}

Node *Edge::getDest() const {
    return dest;
}
