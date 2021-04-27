#include <limits>

#include "NodeD.h"

constexpr auto UINT_MAX = std::numeric_limits<unsigned int>::max();
constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

NodeD::NodeD() : Node() {
    this->dist = DOUBLE_MAX;
    this->path = nullptr;
}

NodeD::NodeD(const Node *node, double dist, Node *path) : Node(*node) {
    this->dist = dist;
    this->path = path;
}
