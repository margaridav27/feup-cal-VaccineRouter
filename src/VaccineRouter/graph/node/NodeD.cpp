#include <limits>

#include "NodeD.h"

constexpr auto UINT_MAX = std::numeric_limits<unsigned int>::max();
constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

template <class T>
NodeD<T>::NodeD() : Node<T>() {
    this->dist = DOUBLE_MAX;
    this->path = nullptr;
}

template <class T>
NodeD<T>::NodeD(const Node<T> *node, double dist, Node<T> *path) : Node<T>(node) {
    this->dist = dist;
    this->path = path;
}
