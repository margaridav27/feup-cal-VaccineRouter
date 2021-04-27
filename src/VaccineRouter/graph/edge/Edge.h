#ifndef SRC_EDGE_H
#define SRC_EDGE_H

#include "../node/Node.h"

template<class T>
class Edge {
private:
    unsigned int id;
    double w;
    Node<T> *dest;
public:
    Edge();
    Edge(unsigned int id, double w, Node<T> *dest);
};


#endif //SRC_EDGE_H
