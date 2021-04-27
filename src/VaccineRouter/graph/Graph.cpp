#include "Graph.h"

template<class T>
unsigned int Graph<T>::getNumNodes() const {
    return nodeSet.size();
}

template<class T>
bool Graph<T>::addNode(unsigned int id, Coordinates coords) {
    return false;
}

template<class T>
bool Graph<T>::removeNode(unsigned int id) {
    return false;
}

template<class T>
Node<T> *Graph<T>::getNode(unsigned int id) {
    return nullptr;
}

template<class T>
bool Graph<T>::addEdge(unsigned int sourceID, unsigned int destID, double weigth) {
    return false;
}

template<class T>
bool Graph<T>::removeEdge(unsigned int id) {
    return false;
}

template<class T>
Edge<T> *Graph<T>::getEdge(unsigned int id) {
    return nullptr;
}


