#ifndef SRC_NODE_H
#define SRC_NODE_H

#include <vector>

#include "../edge/Edge.h"
#include "../../utilities/Coordinates.h"

constexpr auto UINT_MAX = std::numeric_limits<unsigned int>::max();
constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

class Node {
private:
    unsigned int id;
    Coordinates coordinates;
    std::vector<Edge *> adj;
    std::vector<Edge *> outgoing;
    std::vector<Edge *> incoming;
    bool visited;

    double dist;
    Edge *path;

    double euclidianDist;
public:
    Node();
    Node(unsigned int id);
    Node(unsigned int id, const Coordinates &coordinates);
    Node(unsigned int id, std::vector<Edge *> adj);
    Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj);

    unsigned int getId() const;
    double getDist() const;

    const Coordinates &getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);

    const std::vector<Edge *> &getAdj() const;
    std::vector<Edge *> getOutgoing();
    std::vector<Edge *> getIncoming();

    void setAdj(const std::vector<Edge *> &adj);
    void setPath(Edge * n);
    void setDist(double dist);

    void setUnvisited();
    void setVisited();
    bool wasVisited() const;

    void addEdge(Node *dest, double weight);
    bool removeNodeTo(Node *node);


};


#endif //SRC_NODE_H
