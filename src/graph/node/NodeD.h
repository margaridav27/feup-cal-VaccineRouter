#ifndef SRC_NODED_H
#define SRC_NODED_H

#include "Node.h"

template <class T>
class NodeD : public Node {
private:
    double dist;
    Node<T> *path;
public:

};


#endif //SRC_NODED_H
