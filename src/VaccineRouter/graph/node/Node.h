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
    unsigned int lowlink; //to use with tarjan's algorithm
    bool onStack; //to use with tarjan's algorithm
    Coordinates coordinates;
    std::vector<Edge *> adj;
    std::vector<Edge *> outgoing;
    std::vector<Edge *> incoming;
    bool visited;
    double dist;
    Node *path;
    double euclidianDist;
    double cost;
    int queueIndex = 0;

public:
    Node();

    Node(unsigned int id);

    Node(unsigned int id, const Coordinates &coordinates);

    Node(unsigned int id, std::vector<Edge *> adj);

    Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj);

    Node(const Node *node, double euclidianDist);

    unsigned int getId() const;

    unsigned int getLowlink() const;

    void setLowlink(unsigned int lowlink);

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

    std::vector<Edge *> getOutgoing() const;

    std::vector<Edge *> getIncoming() const;

    bool isOnStack() const;

    void pushToStack();

    void popFromStack();

    bool wasVisited() const;

    void setUnvisited();

    void setVisited();

    void addEdge(Node *dest, double weight);

    bool removeNodeTo(Node *node);

    double calculateDist(Node *n);

    bool operator<(Node &n) const;

    bool operator==(Node &n) const;
};


#endif //VACCINEROUTER_NODE_H
