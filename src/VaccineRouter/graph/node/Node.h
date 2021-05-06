#ifndef VACCINEROUTER_NODE_H
#define VACCINEROUTER_NODE_H

#include <vector>
#include <limits>
#include "../edge/Edge.h"
#include "../../utilities/Coordinates.h"
class Edge;

class Node {
private:
    unsigned int id;
    Coordinates coordinates;
    std::vector<Edge *> adj;
    std::vector<Edge *> outgoing;
    std::vector<Edge *> incoming;
    bool visited;
    double dist;
    Node *path;
    double euclidianDist;
    double cost;
    int queueIndex = 0;

public:
    Node();
    Node(unsigned int id);
    Node(unsigned int id, const Coordinates &coordinates);
    Node(unsigned int id, std::vector<Edge *> adj);
    Node(unsigned int id, const Coordinates &coordinates, std::vector<Edge *> adj);
    Node(const Node *node, double euclidianDist);


    unsigned int getId() const;
    double getDist() const;
    int getQueueIndex() const;
    Node* getPath() const;
    Coordinates getCoords() const;
    double getCost() const;
    double getEuclidianDist() const;


  const Coordinates &getCoordinates() const;
    void setCoordinates(const Coordinates &coordinates);

    const std::vector<Edge *> &getAdj() const;
    std::vector<Edge *> getOutgoing();
    std::vector<Edge *> getIncoming();

    void setAdj(const std::vector<Edge *> &adj);
    void setPath(Node * n);
    void setDist(double dist);
    void setEuclidianDist(double eDist);
    void setQueueIndex(int index);
    void setCost (double cost);

    void setUnvisited();
    void setVisited();
    bool wasVisited() const;

    void addEdge(Node *dest, double weight);
    bool removeNodeTo(Node *node);
    double calculateDist(Node *n);

    bool operator<(Node &n) const;
    bool operator==(Node &n) const;
};


#endif //VACCINEROUTER_NODE_H
