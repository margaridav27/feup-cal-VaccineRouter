#include <limits>
#include <utility>

#include "Node.h"

Node::Node() :
        id(UINT_MAX),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
        visited(false) {}

Node::Node(unsigned int id) :
        id(id),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
        visited(false) {}

Node::Node(unsigned int id, const Coordinates &coordinates) :
        id(id),
        coordinates(coordinates),
        visited(false) {}

Node::Node(unsigned int id, std::vector<Edge *> adj) :
        id(id),
        coordinates(Coordinates(DOUBLE_MAX, DOUBLE_MAX)),
        adj(std::move(adj)),
        visited(false) {}

Node::Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj) :
        id(id),
        coordinates(coordinates),
        adj(std::move(adj)),
        visited(false) {}

Node::Node(const NodeD *nodeD, double euclidianDist) :
{
    this->euclidianDist = euclidianDist;
}
unsigned int Node::getId() const { return id; }

double getDist() const { return this->dist; }

const Coordinates &Node::getCoordinates() const { return coordinates; }

void Node::setCoordinates(const Coordinates &coordinates) {
    this->coordinates = coordinates;
}

const std::vector<Edge *> &Node::getAdj() const { return adj; }

void Node::setAdj(const std::vector<Edge *> &adj) { this->adj = adj; }

void Node::setVisited() { visited = true; }

void Node::setUnvisited() { visited = false; }

void Node::setDist(double dist){
    this->dist = dist;
}
void Node::setPath(Node * path){
    this->path = path;
}

bool Node::wasVisited() const { return visited; }

void Node::addEdge(Node *dest, double weight) {
    // COMBACK
    //adj.push_back(new Edge(dest, weight));
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

std::vector<Edge *> Node::getOutgoing(){
    return this->outgoing;
}

std::vector<Edge *> Node::getIncoming(){
    return this->incoming;
}
