#ifndef SRC_NODE_H
#define SRC_NODE_H

#include <vector>

#include "../edge/Edge.h"
#include "../../utilities/Coordinates.h"

class Node {
protected:
    unsigned int id;
    Coordinates coordinates;
    std::vector<Edge *> adj;
public:
    Node();
    Node(unsigned int id);
    Node(unsigned int id, const std::vector<Edge *> &adj);
    Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj);
    Node(Node *node);

    unsigned int getId() const;

    const Coordinates &getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);

    const std::vector<Edge *> &getAdj() const;
    void setAdj(const std::vector<Edge *> &adj);
};

struct NodeHash {
    bool operator()(const Node *node1, const Node *node2) const {
        return node1.getId() == node2.getId();
    }

    int operator()(const Node &d) const {
        return d.getId();
    }
};

typedef std::unordered_set<Node, NodeHash, NodeHash> NodeHashTable;

#endif //SRC_NODE_H
