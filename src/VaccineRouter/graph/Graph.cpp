#include <algorithm>
#include <queue>
#include <unordered_set>

#include "Graph.h"

std::vector<Node *> Graph::getNodeSet() {
    return this->nodeSet;
}

bool Graph::addNode(unsigned int id, Coordinates coords) {
    if (findNode(id) != nullptr) return false;
    nodeSet.push_back(new Node(id, coords));
    return true;
}

bool Graph::removeNode(unsigned int id) {
    Node *toRemove = findNode(id);
    if (toRemove == nullptr) return false;
    for (Node *node : nodeSet) node->removeNodeTo(toRemove);
    nodeSet.erase(std::find(nodeSet.begin(), nodeSet.end(), toRemove));
    return true;
}

bool Graph::addEdge(unsigned int sourceID, unsigned int destID, double weight) {
    Node *source = findNode(sourceID);
    Node *dest = findNode(destID);
    if (source == nullptr || dest == nullptr) return false;
    source->addEdge(dest, weight);
    return true;
}

bool Graph::removeEdge(unsigned int sourceID, unsigned int destID) {
    Node *source = findNode(sourceID);
    Node *dest = findNode(destID);
    if (source != nullptr && dest != nullptr) return source->removeNodeTo(dest);
    return false;
}

Node *Graph::findNode(int id) {
    auto it = nodeHashMap.find(id);
    return it == nodeHashMap.end() ? nullptr : it->second;
}

void Graph::DFSRecursive(Node *start) {
    for (Edge *edge : start->getAdj()) {
        if (!edge->getDest()->wasVisited())
            DFSRecursive(edge->getDest());
    }
}

void Graph::DFSConnectivity(Node *start) {
    for (Node *node : this->nodeSet) node->setUnvisited();
    DFSRecursive(start);
}

void Graph::removeUnvisitedNodes() {
    std::unordered_set<Node *, NodeHash, NodeHash> removed;

    // remove nodes
    for (auto it = this->nodeSet.begin(); it != this->nodeSet.end(); it++) {
        if (!(*it)->wasVisited()) {
            removed.insert((*it));
            removeNode((*it)->getId());
            it--;
        }
    }

    // remove edges
    for (Node *node : this->nodeSet) {
        for (auto it = node->getAdj().begin(); it != node->getAdj().end(); it++) {
            if (removed.find((*it)->getDest()) != removed.end()) {
                removeEdge(node->getId(), (*it)->getDest()->getId());
                removeNode((*it)->getDest()->getId());
                it--;
            }
        }
    }
}
