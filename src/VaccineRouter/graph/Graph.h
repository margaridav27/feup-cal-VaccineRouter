#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H

#include <vector>

#include "node/Node.h"

template<class T>
class Graph {
private:
    std::vector<Node *> nodeSet;
    std::vector<Node *> nodeHashSet;
public:
    unsigned int getNumNodes() const;

    bool addNode(unsigned int id, Coordinates coords);
    bool removeNode(unsigned int id);
    Node *getNode(unsigned int id);

    bool addEdge(unsigned int sourceID, unsigned int destID, double weigth);
    bool removeEdge(unsigned int id);
    Edge *getEdge(unsigned int id);
};


#endif //SRC_GRAPH_H
