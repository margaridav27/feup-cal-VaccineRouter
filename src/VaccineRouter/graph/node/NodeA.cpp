#include <limits>

#include "NodeA.h"

constexpr auto UINT_MAX = std::numeric_limits<unsigned int>::max();
constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

NodeA::NodeA() : NodeD() {}

NodeA::NodeA(const NodeD *nodeD, double euclidianDist) : NodeD(*nodeD) {
    this->euclidianDist = euclidianDist;
}
