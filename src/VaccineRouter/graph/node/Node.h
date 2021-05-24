#ifndef VACCINEROUTER_NODE_H
#define VACCINEROUTER_NODE_H

#include "../../utilities/Coordinates.h"
#include "../edge/Edge.h"
#include <limits>
#include <vector>

class Edge;

/**
 * class Node
 */
class Node {
private:
  unsigned int id;
  Coordinates coordinates;
  std::vector<Edge *> adj;
  bool visited;
  double dist;
  Node *path;
  double cost{};
  int queueIndex = 0;

public:
  /**
   * constructor
   */
  Node();

  /**
   * constructor
   * @param id
   */
  Node(unsigned int id);

  /**
   * constructor
   * @param id
   * @param coordinates
   */
  Node(unsigned int id, const Coordinates &coordinates);

  /**
   *
   * @return node's ID
   */
  unsigned int getId() const;

  /**
   *
   * @return node's distance
   */
  double getDist() const;

  /**
   * sets node's distance to dist
   * @param dist
   */
  void setDist(double dist);

  /**
   *
   * @return index in the mutable queue
   */
  int getQueueIndex() const;

  /**
   * sets queue index to index
   * @param index
   */
  void setQueueIndex(int index);

  /**
   *
   * @return incoming node
   */
  Node *getPath() const;

  /**
   * sets incoming node
   * @param n
   */
  void setPath(Node *n);

  /**
   *
   * @return node's coordinates
   */
  const Coordinates &getCoordinates() const;
  /**
   *
   * @return node's cost
   */
  double getCost() const;

  /**
   * sets cost value
   * @param cost
   */
  void setCost(double cost);

  /**
   * returns adjacent edeges
   * @return
   */
  const std::vector<Edge *> &getAdj() const;

  /**
   *
   * @return true if node is visited, false otherwise
   */
  bool wasVisited() const;

  /**
   * sets variable visited to false
   */
  void setUnvisited();

  /**
   * sets variable visited to true
   */
  void setVisited();

  /**
   * adds new edge to the adjacent edges vector
   * @param dest
   * @param weight is the distance between the current node and the dest node
   */
  void addEdge(Node *dest, double weight);

  /**
   * removes connections to node node
   * @param node
   * @return
   */
  bool removeNodeTo(Node *node);

  /**
   * calculates distance between self and node n
   * @param n
   * @return
   */
  double calculateDist(Node *n);

  /**
   *
   * @param n
   * @return true if self distance is minor than n distance
   */
  bool operator<(Node &n) const;
  /**
   *
   * @param n
   * @return true if equal to self, false otherwise
   */
  bool operator==(Node &n) const;
};

struct NodeHash {
  bool operator()(const Node *n1, const Node *n2) const {
    return n1->getId() == n2->getId();
  }

  int operator()(const Node *n) const { return n->getId(); }
};

#endif // VACCINEROUTER_NODE_H
