#ifndef VACCINEROUTER_CENTER_H
#define VACCINEROUTER_CENTER_H

#include "../graph/node/Node.h"
#include <string>
/**
 * Class Center
 */
class Center {
protected:
  Node *node;
  std::string name;
  bool visited;

public:
  /**
   * Default constructor
   */
  Center();

  /**
   * Constructor
   * @param node corresponding graph node
   * @param name name of the Center
   */
  Center(Node *node, std::string name);

  /**
   *
   * @return its corresponding node
   */
  Node *getNode() const;

  /**
   *
   * @return its name
   */
  const std::string &getName() const;

  /**
   *
   * @return wether it is visited or not
   */
  bool isVisited() const;

  /**
   * sets its parameter visited to true
   */
  void setVisited();

  /**
   * sets its parameter visited to false
   */
  void setUnvisited();

  /**
   *
   * @param rhs
   * @return thue if rhs is equal to itself
   */
  bool operator==(const Center &rhs) const;
};

#endif // VACCINEROUTER_CENTER_H
