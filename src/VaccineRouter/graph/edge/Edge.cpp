#include "Edge.h"

Edge::Edge() {}

Edge::Edge(unsigned int id, double w, Node *dest) :
    id(id),
    w(w),
    dest(dest) {}


