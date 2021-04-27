#include <limits>

#include "Node.h"

constexpr auto UINT_MAX = std::numeric_limits<unsigned int>::max();
constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

Node::Node() :
        id(UINT_MAX),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)) {}

Node::Node(unsigned int id) :
        id(id),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)) {}

Node::Node(unsigned int id, const std::vector<Edge *> &adj) :
        id(id),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
        adj(adj) {}

Node::Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj) :
        id(id),
        coordinates(coordinates),
        adj(std::move(adj)) {}

unsigned int Node::getId() const {
    return id;
}

const Coordinates &Node::getCoordinates() const {
    return coordinates;
}

void Node::setCoordinates(const Coordinates &coordinates) {
    this->coordinates = coordinates;
}

const std::vector<Edge *> &Node::getAdj() const {
    return adj;
}

void Node::setAdj(const std::vector<Edge *> &adj) {
    this->adj = adj;
}
