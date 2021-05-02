#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H

#include <vector>

#include "node/Node.h"
#include "edge/Edge.h"
#include "../utilities/Coordinates.h"

class Graph {
private:
    std::vector<Node *> nodeSet;

    void _dfs(Node *node, std::vector<Node *> &res) const;
public:
    Node *getNode(unsigned int id);
    std::vector<Node *> getNodeSet();
    bool addNode(unsigned int id, Coordinates coords);
    bool removeNode(unsigned int id);

    bool addEdge(unsigned int sourceID, unsigned int destID, double weigth);
    bool removeEdge(unsigned int sourceID, unsigned int destID);

    std::vector<Node *> dfs();
    std::vector<Node *> bfs(unsigned int sourceID);


};


#endif //SRC_GRAPH_H
