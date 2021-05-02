#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H

#include <vector>

#include "node/Node.h"
#include "edge/Edge.h"
<<<<<<< HEAD
#include "../utilities/Coordinates.h"
=======
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f

class Graph {
private:
    std::vector<Node *> nodeSet;

    void _dfs(Node *node, std::vector<Node *> &res) const;
public:
    Node *getNode(unsigned int id);
<<<<<<< HEAD
    std::vector<Node *> getNodeSet();
=======
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f
    bool addNode(unsigned int id, Coordinates coords);
    bool removeNode(unsigned int id);

    bool addEdge(unsigned int sourceID, unsigned int destID, double weigth);
    bool removeEdge(unsigned int sourceID, unsigned int destID);

    std::vector<Node *> dfs();
    std::vector<Node *> bfs(unsigned int sourceID);
<<<<<<< HEAD


=======
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f
};


#endif //SRC_GRAPH_H
