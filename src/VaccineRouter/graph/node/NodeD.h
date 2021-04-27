#ifndef SRC_NODED_H
#define SRC_NODED_H

#include "Node.h"

template <class T>
class NodeD : public Node<T> {
private:
    double dist{};
    Node<T> *path;
public:
    NodeD();
    NodeD(const Node<T> *node, double dist, Node<T> *path);
};


#endif //SRC_NODED_H
