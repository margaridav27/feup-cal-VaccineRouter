#ifndef SRC_NODE_H
#define SRC_NODE_H

#include <vector>

#include "../edge/Edge.h"
#include "../../utilities/Coordinates.h"

<<<<<<< HEAD
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
=======
class Node {
protected:
    unsigned int id;
    Coordinates coordinates;
    std::vector<Edge *> adj;
    bool visited;
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f
public:
    Node();
    Node(unsigned int id);
    Node(unsigned int id, const Coordinates &coordinates);
    Node(unsigned int id, std::vector<Edge *> adj);
    Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj);

    unsigned int getId() const;
<<<<<<< HEAD
    double getDist() const;

    const Coordinates &getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);

    const std::vector<Edge *> &getAdj() const;
    std::vector<Edge *> getOutgoing();
    std::vector<Edge *> getIncoming();

    void setAdj(const std::vector<Edge *> &adj);
    void setPath(Edge * n);
    void setDist(double dist);
=======
    const Coordinates &getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);
    const std::vector<Edge *> &getAdj() const;
    void setAdj(const std::vector<Edge *> &adj);
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f

    void setUnvisited();
    void setVisited();
    bool wasVisited() const;

    void addEdge(Node *dest, double weight);
    bool removeNodeTo(Node *node);
<<<<<<< HEAD


=======
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f
};


#endif //SRC_NODE_H
