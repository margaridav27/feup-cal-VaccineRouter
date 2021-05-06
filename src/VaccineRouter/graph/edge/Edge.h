#ifndef VACCINEROUTER_EDGE_H
#define VACCINEROUTER_EDGE_H

#include <limits>
#include "../node/Node.h"

class Node;

constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

class Edge {
private:
    Node *orig;
    Node *dest;
    double weight;
    double capacity;
    double cost;
    double flow;
public:
    Edge();
    Edge(Node *dest, double weight);
    double getWeight() const;
    Node *getOrig() const;
    Node *getDest() const;
    double getCapacity() const;
    double getFlow() const;
    double getCost() const;
};


#endif //VACCINEROUTER_EDGE_H_EDGE_H
