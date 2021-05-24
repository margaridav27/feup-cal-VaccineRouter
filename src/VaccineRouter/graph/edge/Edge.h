#ifndef VACCINEROUTER_EDGE_H
#define VACCINEROUTER_EDGE_H

#include <limits>
#include "../node/Node.h"

class Node;

constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

/*
 * class Edge
 */
class Edge {
private:
    Node *orig;
    Node *dest;
    double weight;
    double capacity;
    double cost;
    double flow;
public:
  /**
   * constructor
   */
    Edge();

    /**
     * constructor
     * @param source
     * @param dest
     * @param weight
     */
    Edge(Node *source, Node *dest, double weight);

    /**
     *
     * @return edge's weight - distance between the two nodes it connects
     */
    double getWeight() const;

    /**
     *
     * @return origin node
     */
    Node *getOrig() const;

    /**
     *
     * @return destination node
     */
    Node *getDest() const;



    /**
     * used in A* algorithm
     * @return cost
     */
    double getCost() const;
};


#endif //VACCINEROUTER_EDGE_H_EDGE_H
