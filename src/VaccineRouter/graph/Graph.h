#ifndef VACCINEROUTER_GRAPH_H
#define VACCINEROUTER_GRAPH_H

#include <vector>
#include <unordered_map>

#include "node/Node.h"
#include "edge/Edge.h"
#include "../utilities/Coordinates.h"


class Graph {
private:
    std::vector<Node *> nodeSet;
    std::unordered_map<int, Node *> nodeHashMap;

    void DFSRecursive(Node *start);
public:
    std::vector<Node *> getNodeSet();
    
    bool addNode(unsigned int id, Coordinates coords);
    bool removeNode(unsigned int id);
    Node *findNode(unsigned int id);
    
    bool addEdge(unsigned int sourceID, unsigned int destID, double weight);
    bool removeEdge(unsigned int sourceID, unsigned int destID);

    void DFSConnectivity(Node *start);
    void removeUnvisitedNodes();
};


#endif //VACCINEROUTER_GRAPH_H
