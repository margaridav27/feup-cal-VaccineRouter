#include "Edge.h"

template<class T>
Edge<T>::Edge() {}

template<class T>
Edge<T>::Edge(unsigned int id, double w, Node<T> *dest) :
    id(id),
    w(w),
    dest(dest) {}


