#ifndef SRC_EDGE_H
#define SRC_EDGE_H

#include "../node/Node.h"

constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

class Edge {
private:
    Node * orig;
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


#endif //SRC_EDGE_H
