#ifndef VACCINEROUTER_NODE_H
#define VACCINEROUTER_NODE_H

#include <vector>
#include <limits>
#include "../edge/Edge.h"
#include "../../utilities/Coordinates.h"

class Edge;

class Node {
private:
    unsigned int id;
    Coordinates coordinates;
    std::vector<Edge *> adj;
    bool visited;
    double dist;
    Node *path;
    double euclidianDist;
    double cost{};
    int queueIndex = 0;
public:
    Node();
    Node(unsigned int id);
    Node(unsigned int id, const Coordinates &coordinates);

    unsigned int getId() const;

    double getDist() const;
    void setDist(double dist);

    int getQueueIndex() const;
    void setQueueIndex(int index);

    Node *getPath() const;
    void setPath(Node *n);

    const Coordinates &getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);

    double getCost() const;
    void setCost(double cost);

    double getEuclidianDist() const;
    void setEuclidianDist(double eDist);

    const std::vector<Edge *> &getAdj() const;
    void setAdj(const std::vector<Edge *> &adj);

    bool wasVisited() const;
    void setUnvisited();
    void setVisited();

    void addEdge(Node *dest, double weight);

    bool removeNodeTo(Node *node);

    double calculateDist(Node *n);

    bool operator<(Node &n) const;
    bool operator==(Node &n) const;
};

struct NodeHash {
    bool operator()(const Node *n1, const Node *n2) const {
        return n1->getId() == n2->getId();
    }

    int operator()(const Node *n) const {
        return n->getId();
    }
};

#endif //VACCINEROUTER_NODE_H
