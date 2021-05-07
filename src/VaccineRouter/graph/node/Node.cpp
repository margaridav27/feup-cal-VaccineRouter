#include <limits>
#include <utility>

#include "Node.h"

constexpr auto UI_MAX = std::numeric_limits<double>::max();

Node::Node() :
        id(UI_MAX),
        lowlink(UI_MAX),
        onStack(false),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
        visited(false),
        dist(DOUBLE_MAX),
        path(nullptr) {}

Node::Node(unsigned int id) :
        id(id),
        lowlink(id),
        onStack(false),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
        visited(false),
        dist(DOUBLE_MAX),
        path(nullptr) {}

Node::Node(unsigned int id, const Coordinates &coordinates) :
        id(id),
        lowlink(id),
        onStack(false),
        coordinates(coordinates),
        visited(false),
        dist(DOUBLE_MAX),
        path(nullptr) {}

Node::Node(unsigned int id, std::vector<Edge *> adj) :
        id(id),
        lowlink(id),
        onStack(false),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
        adj(std::move(adj)),
        visited(false),
        dist(DOUBLE_MAX), path(nullptr) {}

Node::Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj) :
        id(id),
        lowlink(id),
        onStack(false),
        coordinates(coordinates),
        adj(std::move(adj)),
        visited(false),
        dist(DOUBLE_MAX),
        path(nullptr) {}

Node::Node(const Node *node, double euclidianDist) :
        id(node->id),
        lowlink(node->id),
        onStack(false),
        coordinates(node->coordinates),
        adj(node->adj),
        visited(false),
        euclidianDist(euclidianDist),
        dist(DOUBLE_MAX),
        path(nullptr) {}

unsigned int Node::getId() const { return this->id; }

unsigned int Node::getLowlink() const { return this->lowlink; }

bool Node::isOnStack() const { return this->onStack; }

double Node::getDist() const { return this->dist; }

int Node::getQueueIndex() const { return this->queueIndex; }

Node *Node::getPath() const { return this->path; }

Coordinates Node::getCoords() const { return this->coordinates; }

double Node::getCost() const { return this->cost; }

double Node::getEuclidianDist() const { return this->euclidianDist; }

const Coordinates &Node::getCoordinates() const { return coordinates; }

std::vector<Edge *> Node::getOutgoing() const { return this->outgoing; }

std::vector<Edge *> Node::getIncoming() const { return this->incoming; }

const std::vector<Edge *> &Node::getAdj() const { return adj; }

void Node::setCoordinates(const Coordinates &coordinates) {
    this->coordinates = coordinates;
}

void Node::setAdj(const std::vector<Edge *> &adj) { this->adj = adj; }

void Node::setLowlink(unsigned int lowlink) { this->lowlink = lowlink; }

void Node::setVisited() { visited = true; }

void Node::setUnvisited() { visited = false; }

void Node::setDist(double dist) { this->dist = dist; }

void Node::setEuclidianDist(double eDist) { this->euclidianDist = eDist; }

void Node::setPath(Node *path) { this->path = path; }

void Node::setQueueIndex(int index) { this->queueIndex = index; }

void Node::setCost(double cost) { this->cost = cost; }

void Node::pushToStack() { this->onStack = true; }

void Node::popFromStack() { this->onStack = false; }

bool Node::wasVisited() const { return visited; }

void Node::addEdge(Node *dest, double weight) { adj.push_back(new Edge(dest, weight)); }

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
    return this->coordinates.calculateEuclidianDistance(n->getCoordinates());
}

bool Node::operator<(Node &node) const {
    if (this->dist == node.getDist())
        return this->euclidianDist < node.euclidianDist;
    return this->dist < node.getDist();
}

bool Node::operator==(Node &n) const { return this->id == n.getId(); }

