#ifndef SRC_NODE_H
#define SRC_NODE_H

#include <vector>

#include "../edge/Edge.h"
#include "../../utilities/Coordinates.h"

template<class T>
class Node {
protected:
    unsigned int id;
    Coordinates coordinates;
    std::vector<Edge<T> *> adj;
public:

};


#endif //SRC_NODE_H
