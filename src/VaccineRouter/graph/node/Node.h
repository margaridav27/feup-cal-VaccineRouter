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
    Node();
    Node(unsigned int id);
    Node(unsigned int id, const std::vector<Edge<T> *> &adj);
    Node(unsigned int id, const Coordinates &coordinates, const std::vector<Edge<T> *> &adj);

    unsigned int getId() const;

    const Coordinates &getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);

    const std::vector<Edge<T> *> &getAdj() const;
    void setAdj(const std::vector<Edge<T> *> &adj);
};


#endif //SRC_NODE_H
