#include <algorithm>
#include <queue>

#include "Graph.h"

Node *Graph::getNode(unsigned int id) {
    for (auto node : nodeSet) {
        if (node->getId() == id) return node;
    }
    return nullptr;
}

std::vector<Node *> Graph::getNodeSet(){
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

void Graph::_dfs(Node *node, std::vector<Node *> &res) const {
if (!node->wasVisited()) {
res.push_back(node);
node->setVisited();
for (auto &edge : node->getAdj()) _dfs(edge->getDest(), res);
}
    if (!node->wasVisited()) {
        res.push_back(node);
        node->setVisited();
        for (auto &edge : node->getAdj()) _dfs(edge->getDest(), res);
    }
}

std::vector<Node *> Graph::dfs() {
    std::vector<Node *> res;

    Node *node = nodeSet[0];
    bool notAllVisited = true;

    while (notAllVisited) {
        _dfs(node, res);

        notAllVisited = false;

        for (auto n : nodeSet) {
            if (!n->wasVisited()) {
                notAllVisited = true;
                n = node; // COMBACK for some reason node is not being used
                break;
            }
        }
    }

    for (auto node : nodeSet) node->setUnvisited();

    return res;
}

std::vector<Node *> Graph::bfs(unsigned int sourceID) {
    std::vector<Node *> res;

    Node *node = getNode(sourceID);
    if (node == nullptr) return res;

    std::queue<Node *> toVisit;
    toVisit.push(node);

    while (!toVisit.empty()) {
        node = toVisit.front();
        toVisit.pop();
        if (!node->wasVisited()) {
            res.push_back(node);
            node->setVisited();
            for (auto edge : node->getAdj()) toVisit.push(edge->getDest());
        }
    }

    for (auto node : nodeSet) node->setUnvisited();

    return res;
}
Node* Graph::findNode(Node * nO) {
  for(Node *n: nodeSet){
    if (n == nO)
        return n;
  }
  return nullptr;
}
