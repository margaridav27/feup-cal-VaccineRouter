#include <limits>

#include "NodeA.h"

constexpr auto UINT_MAX = std::numeric_limits<unsigned int>::max();
constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

template<class T>
NodeA<T>::NodeA() : NodeD<T>() {}

template<class T>
NodeA<T>::NodeA(const NodeD<T> *nodeD, double euclidianDist) : NodeD<T>(nodeD) {
    this->euclidianDist = euclidianDist;
}
