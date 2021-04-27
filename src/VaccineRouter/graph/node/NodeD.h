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

struct NodeHash {
    bool operator()(const Node &node1, const Node &node2) const { return node1.getId() == node2.getId(); }
    int operator()(const Node &node) const { return node.getId(); }
};

// TODO redefine hash

#endif //SRC_NODED_H
