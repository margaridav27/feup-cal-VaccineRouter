#ifndef VACCINEROUTER_APPLICATIONCENTER_H
#define VACCINEROUTER_APPLICATIONCENTER_H

#include "../graph/node/Node.h"
#include "Center.h"
#include <string>
/**
 * Class ApplicationCenter
 */
class ApplicationCenter : public Center {
private:
  unsigned int vaccinesToReceive;

public:
  /**
   * Default Constructor
   */
  ApplicationCenter();

  /**
   * Constructor
   * @param node corresponding graph node
   * @param name corresponding name
   */
  ApplicationCenter(Node *node, const std::string &name);

  /**
   *
   * @return the number of vaccines to receive
   */
  unsigned int getVaccinesToReceive() const;

  /**
   * sets the number of vaccines to receive
   * @param order
   */
  void setVaccinesToReceive(unsigned int order);

  /**
   *
   * @param rhs
   * @return true if rhs is equal to self, false otherwise
   */
  bool operator==(const ApplicationCenter *rhs) const;
};

/**
 *
 * @param out
 * @return
 */
std::ostream &operator<<(std::ostream &out, ApplicationCenter *ac);

#endif // VACCINEROUTER_APPLICATIONCENTER_H
