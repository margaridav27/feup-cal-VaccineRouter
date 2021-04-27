#ifndef SRC_NODEA_H
#define SRC_NODEA_H

#include "NodeD.h"

template<class T>
class NodeA : public NodeD<T> {
private:
    double euclidianDist{};
public:
    NodeA();
    NodeA(const NodeD<T> *nodeD, double euclidianDist);
};


#endif //SRC_NODEA_H
