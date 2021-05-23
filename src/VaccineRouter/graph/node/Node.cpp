#include <limits>
#include <utility>

#include "Node.h"

constexpr auto UI_MAX = std::numeric_limits<double>::max();

Node::Node() :
        id(UI_MAX),
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

unsigned int Node::getId() const { return this->id; }

double Node::getDist() const { return this->dist; }

void Node::setDist(double dist) { this->dist = dist; }

int Node::getQueueIndex() const { return this->queueIndex; }

void Node::setQueueIndex(int index) { this->queueIndex = index; }

Node *Node::getPath() const { return this->path; }

void Node::setPath(Node *path) { this->path = path; }

double Node::getCost() const { return this->cost; }

void Node::setCost(double cost) { this->cost = cost; }

double Node::getEuclideanDist() const { return this->euclideanDist; }

void Node::setEuclideanDist(double eDist) { this->euclideanDist = eDist; }

const Coordinates &Node::getCoordinates() const { return coordinates; }

void Node::setCoordinates(const Coordinates &coordinates) {
    this->coordinates = coordinates;
}

const std::vector<Edge *> &Node::getAdj() const { return adj; }

void Node::setAdj(const std::vector<Edge *> &adj) { this->adj = adj; }

bool Node::wasVisited() const { return visited; }

void Node::setVisited() { visited = true; }

void Node::setUnvisited() { visited = false; }

void Node::addEdge(Node *dest, double weight) { adj.push_back(new Edge(this, dest, weight)); }

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
    return this->coordinates.calculateEuclideanDistance(n->getCoordinates());
}

bool Node::operator<(Node &node) const {
    if (this->dist == node.getDist())
        return this->euclideanDist < node.euclideanDist;
    return this->dist < node.getDist();
}

bool Node::operator==(Node &n) const { return this->id == n.getId(); }

