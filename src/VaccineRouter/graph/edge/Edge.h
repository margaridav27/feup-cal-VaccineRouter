#ifndef SRC_EDGE_H
#define SRC_EDGE_H

#include "../node/Node.h"

class Edge {
private:
    unsigned int id;
    double w;
    Node *dest;
public:
    Edge();
    Edge(unsigned int id, double w, Node *dest);
};


#endif //SRC_EDGE_H
