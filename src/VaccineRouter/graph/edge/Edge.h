#ifndef SRC_EDGE_H
#define SRC_EDGE_H

#include "../node/Node.h"

<<<<<<< HEAD
constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

class Edge {
private:
    Node * orig;
    Node *dest;
    double weight;
    double capacity;
    double cost;
    double flow;
=======
class Edge {
private:
    double weight;
    Node *dest;
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f
public:
    Edge();
    Edge(Node *dest, double weight);

    double getWeight() const;
<<<<<<< HEAD
    Node *getOrig() const;
    Node *getDest() const;
    double getCapacity() const;
    double getFlow() const;
    double getCost() const;
=======
    Node *getDest() const;
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f
};


#endif //SRC_EDGE_H
