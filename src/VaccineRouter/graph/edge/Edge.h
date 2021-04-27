#ifndef SRC_EDGE_H
#define SRC_EDGE_H

#include "../node/Node.h"

class Edge {
private:
    double weight;
    Node *dest;
public:
    Edge();
    Edge(Node *dest, double weight);

    double getWeight() const;
    Node *getDest() const;
};


#endif //SRC_EDGE_H
