#include <limits>
#include <utility>

#include "Node.h"

constexpr auto UI_MAX = std::numeric_limits<double>::max();

Node::Node() :
        id(),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
        visited(false),
        dist(DOUBLE_MAX),
        path(nullptr) {}

Node::Node(unsigned int id) :
        id(id),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
        visited(false),
        dist(DOUBLE_MAX),
        path(nullptr) {}

Node::Node(unsigned int id, const Coordinates &coordinates) :
        id(id),
        coordinates(coordinates),
        visited(false),
        dist(DOUBLE_MAX),
        path(nullptr) {}

Node::Node(unsigned int id, std::vector<Edge *> adj) :
        id(id),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
        adj(std::move(adj)),
        visited(false),
        dist(DOUBLE_MAX), path(nullptr) {}

Node::Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj) :
        id(id),
        coordinates(coordinates),
        adj(std::move(adj)),
        visited(false),
        dist(DOUBLE_MAX),
        path(nullptr) {}

Node::Node(const Node *node, double euclidianDist) :
        id(node->id),
        coordinates(node->coordinates),
        adj(std::move(node->adj)),
        visited(false),
        euclidianDist(euclidianDist),
        dist(DOUBLE_MAX),
        path(nullptr) {}

unsigned int Node::getId() const { return id; }

double Node::getDist() const { return this->dist; }

int Node::getQueueIndex() const { return this->queueIndex; }

Node *Node::getPath() const { return this->path; }

Coordinates Node::getCoords() const { return this->coordinates; }

double Node::getCost() const { return this->cost; }

double Node::getEuclidianDist() const { return this->euclidianDist; }

const Coordinates &Node::getCoordinates() const { return coordinates; }

void Node::setCoordinates(const Coordinates &coordinates) {
    this->coordinates = coordinates;
}

const std::vector<Edge *> &Node::getAdj() const { return adj; }

void Node::setAdj(const std::vector<Edge *> &adj) { this->adj = adj; }

void Node::setVisited() { visited = true; }

void Node::setUnvisited() { visited = false; }

void Node::setDist(double dist) {
    this->dist = dist;
}

void Node::setEuclidianDist(double eDist) { this->euclidianDist = eDist; }

void Node::setPath(Node *path) {
    this->path = path;
}

void Node::setQueueIndex(int index) {
    this->queueIndex = index;
}

void Node::setCost(double cost) { this->cost = cost; }

bool Node::wasVisited() const { return visited; }

void Node::addEdge(Node *dest, double weight) {
    adj.push_back(new Edge(dest, weight));
}

bool Node::removeNodeTo(Node *node) {
    for (auto iter = adj.begin(); iter != adj.end(); iter++) {
        if ((*iter)->getDest() == node) {
            adj.erase(iter);
            return true;
        }
    }
    return false;
}

double Node::calculateDist(Node *n) {
    this->coordinates
            .calculateEuclidianDistance(n->getCoordinates());
}

std::vector<Edge *> Node::getOutgoing() {
    return this->outgoing;
}

std::vector<Edge *> Node::getIncoming() {
    return this->incoming;
}

bool Node::operator<(Node &node) const {
    if (this->dist == node.getDist())
        return this->euclidianDist < node.euclidianDist;
    return this->dist < node.getDist();
}

bool Node::operator==(Node &n) const { return this->id == n.getId(); }
