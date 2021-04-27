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
    bool visited;
public:
    Node();
    Node(unsigned int id);
    Node(unsigned int id, const Coordinates &coordinates);
    Node(unsigned int id, std::vector<Edge *> adj);
    Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj);

    unsigned int getId() const;
    const Coordinates &getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);
    const std::vector<Edge *> &getAdj() const;
    void setAdj(const std::vector<Edge *> &adj);

    void setUnvisited();
    void setVisited();
    bool wasVisited() const;

    void addEdge(Node *dest, double weight);
    bool removeNodeTo(Node *node);
};


#endif //SRC_NODE_H
