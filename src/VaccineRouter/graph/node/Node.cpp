#include "Node.h"

template<class T>
Node<T>::Node() {}

template<class T>
Node<T>::Node(unsigned int id)
    :id(id) {}

template<class T>
Node<T>::Node(unsigned int id, const std::vector<Edge<T> *> &adj)
    :id(id), adj(adj) {}

template<class T>
Node<T>::Node(unsigned int id, const Coordinates &coordinates, const std::vector<Edge<T> *> &adj)
    :id(id), coordinates(coordinates), adj(adj) {}

template<class T>
unsigned int Node<T>::getId() const { return id; }

template<class T>
const Coordinates &Node<T>::getCoordinates() const { return coordinates; }

template<class T>
void Node<T>::setCoordinates(const Coordinates &coordinates) { this->coordinates = coordinates; }

template<class T>
const std::vector<Edge<T> *> &Node<T>::getAdj() const { return adj; }

template<class T>
void Node<T>::setAdj(const std::vector<Edge<T> *> &adj) { this->adj = adj; }
