#include <limits>

#include "Node.h"

constexpr auto UINT_MAX = std::numeric_limits<unsigned int>::max();
constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

template<class T>
Node<T>::Node() :
    id(UINT_MAX),
    coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX))
    {}

template<class T>
Node<T>::Node(unsigned int id) :
    id(id),
    coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX))
    {}

template<class T>
Node<T>::Node(unsigned int id, const std::vector<Edge<T> *> &adj) :
    id(id),
    coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
    adj(adj)
    {}

template<class T>
Node<T>::Node(unsigned int id, const Coordinates &coordinates, const std::vector<Edge<T> *> &adj) :
    id(id),
    coordinates(coordinates),
    adj(adj)
    {}

template<class T>
unsigned int Node<T>::getId() const {
    return id;
}

template<class T>
const Coordinates &Node<T>::getCoordinates() const {
    return coordinates;
}

template<class T>
void Node<T>::setCoordinates(const Coordinates &coordinates) {
    this->coordinates = coordinates;
}

template<class T>
const std::vector<Edge<T> *> &Node<T>::getAdj() const {
    return adj;
}

template<class T>
void Node<T>::setAdj(const std::vector<Edge<T> *> &adj) {
    this->adj = adj;
}
