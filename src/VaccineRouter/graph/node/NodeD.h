#ifndef SRC_NODED_H
#define SRC_NODED_H

#include "Node.h"

class NodeD : public Node {
private:
    double dist{};
    Node *path;
public:
    NodeD();
    NodeD(const Node *node, double dist, Node *path);
};


#endif //SRC_NODED_H
