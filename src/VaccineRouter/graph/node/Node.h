#ifndef SRC_NODE_H
#define SRC_NODE_H

#include <vector>

#include "../edge/Edge.h"
#include "../../utilities/Coordinates.h"

class Node {
protected:
    unsigned int id;
    Coordinates coordinates;
    std::vector<Edge *> adj;
public:
    Node();
    Node(unsigned int id);
    Node(unsigned int id, const std::vector<Edge *> &adj);
    Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj);
    Node(Node *node);

    unsigned int getId() const;

    const Coordinates &getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);

    const std::vector<Edge *> &getAdj() const;
    void setAdj(const std::vector<Edge *> &adj);
};

// TODO define hash

#endif //SRC_NODE_H
