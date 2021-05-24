#ifndef VACCINEROUTER_EDGE_H
#define VACCINEROUTER_EDGE_H

#include <limits>
#include "../node/Node.h"

class Node;

constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

/*
 * class Edge
 */
class Edge {
private:
    Node *orig;
    Node *dest;
    double weight;
    double cost;
    double flow;
public:
    Edge();
    Edge(Node *source, Node *dest, double weight);

    double getWeight() const;

    double getCost() const;

    Node *getOrig() const;

    Node *getDest();
};


#endif //VACCINEROUTER_EDGE_H_EDGE_H
