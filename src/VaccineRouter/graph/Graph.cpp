#include <algorithm>
#include <queue>

#include "Graph.h"

Node *Graph::getNode(unsigned int id) {
    for (auto node : nodeSet) {
        if (node->getId() == id) return node;
    }
    return nullptr;
}

std::vector<Node *> Graph::getNodeSet() {
    return this->nodeSet;
}

bool Graph::addNode(unsigned int id, Coordinates coords) {
    if (getNode(id) != nullptr) return false;
    nodeSet.push_back(new Node(id, coords));
    return true;
}

bool Graph::removeNode(unsigned int id) {
    Node *toRemove = getNode(id);
    if (toRemove == nullptr) return false;
    for (Node *node : nodeSet) node->removeNodeTo(toRemove);
    nodeSet.erase(std::find(nodeSet.begin(), nodeSet.end(), toRemove));
    return true;
}

bool Graph::addEdge(unsigned int sourceID, unsigned int destID, double weigth) {
    Node *source = getNode(sourceID);
    Node *dest = getNode(destID);
    if (source == nullptr || dest == nullptr) return false;
    source->addEdge(dest, weigth);
    return true;
}

bool Graph::removeEdge(unsigned int sourceID, unsigned int destID) {
    Node *source = getNode(sourceID);
    Node *dest = getNode(destID);
    if (source != nullptr && dest != nullptr) return source->removeNodeTo(dest);
    return false;
}

Node *Graph::findNode(Node *nO) {
    for (Node *n: nodeSet) {
        if (n == nO)
            return n;
    }
    return nullptr;
}
