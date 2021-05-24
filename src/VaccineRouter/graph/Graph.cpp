#include <algorithm>
#include <queue>
#include <unordered_set>

#include "Graph.h"

std::vector<Node *> Graph::getNodeSet() {
    return this->nodeSet;
}

bool Graph::addNode(unsigned int id, Coordinates coords) {
    if (findNode(id) != nullptr) return false;
    Node *newNode = new Node(id, coords);
    nodeSet.push_back(newNode);
    nodeHashMap.insert(std::pair<unsigned int, Node *>(id, newNode));
    return true;
}

bool Graph::removeNode(unsigned int id) {
    Node *toRemove = findNode(id);
    if (toRemove == nullptr) return false;
    for (Node *node : nodeSet) node->removeNodeTo(toRemove);
    nodeSet.erase(std::find(nodeSet.begin(), nodeSet.end(), toRemove));
    nodeHashMap.erase(nodeHashMap.find(id));
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

Node *Graph::findNode(unsigned int id) {
    auto it = nodeHashMap.find(id);
    return it == nodeHashMap.end() ? nullptr : it->second;
}

void Graph::DFSRecursive(Node *start) {
    start->setVisited();
    for (Edge *edge : start->getAdj()) {
        if (!edge->getDest()->wasVisited())
            DFSRecursive(edge->getDest());
    }
}

void Graph::DFSConnectivity(Node *start) {
    if (!start->wasVisited())
        DFSRecursive(start);
}

void Graph::removeUnvisitedNodes() {
    std::unordered_set<Node *, NodeHash, NodeHash> removed;

    // remove nodes
    for (auto itNode = this->nodeSet.begin(); itNode != this->nodeSet.end(); itNode++) {
        if (!(*itNode)->wasVisited()) {
            removed.insert((*itNode));
            removeNode((*itNode)->getId());
            itNode--;
        }
    }

    // remove edges
    for (Node *node : this->nodeSet) {
        for (auto itEdge = node->getAdj().begin(); itEdge != node->getAdj().end(); itEdge++) {
            if (removed.find((*itEdge)->getDest()) != removed.end()) {
                removeEdge(node->getId(), (*itEdge)->getDest()->getId());
                removeNode((*itEdge)->getDest()->getId());
                itEdge--;
            }
        }
    }
}
