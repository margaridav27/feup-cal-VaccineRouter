#ifndef SRC_NODEA_H
#define SRC_NODEA_H

#include "NodeD.h"

class NodeA : public NodeD {
private:
    double euclidianDist;
public:
    NodeA();
    NodeA(const NodeD *nodeD, double euclidianDist);
};


#endif //SRC_NODEA_H
