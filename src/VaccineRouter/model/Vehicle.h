#ifndef SRC_VEHICLE_H
#define SRC_VEHICLE_H

#include "../graph/Graph.h"
#include "../graph/node/Node.h"
#include "../utilities/Time.h"

#include <stack>
#include <vector>

/**
 * class Vehicle
 */
class Vehicle {
private:
  std::stack<Node *> qPath;
  std::vector<Node *> vPath;
  double speed = 70;
  Time pathDuration;
  Time maxPathDuration;

  /**
   * adds a node to this vehicle's path vector
   * @param path
   */
  void addToPath(std::vector<Node *> path);

public:
  /**
   * constructor
   */
  Vehicle();

  /**
   * constructor
   * @param maxPathDuration
   */
  Vehicle(Time maxPathDuration);

  /**
   *
   * @return vehicle's path
   */
  std::vector<Node *> getPath();

  /**
   *
   * @return duration of the current path
   */
  Time *getPathDuration();

  /**
  * calculates the current path duration according to path distance and
  * its velocity
  * @param path
  * @return the duration of the path
  */
  Time getPathDuration(std::vector<Node *> path) const;

  /**
   * attempts to insert a path in this vehicle
   * @param path path to be added to this vehicle
   * @param checkTW is true if maximum time window must be considered,
   * false if time window can be ignored
   * @return true if the given path duration is within the maximum time window
   */
  bool setVehicleRoute(const std::vector<Node *> &path, bool checkTW);

  /**
   * sets the vehicle path to the param oldPath
   * @param oldPath
   */
  void setPath(std::vector<Node *> oldPath);

  void setMaxPathDuration(const Time &maxPathDuration);

  /**
   *
   * @return true if path is empty, false otherwise
   */
  bool hasEmptyPath() const;

  /**
   *
   * @param rhs
   * @return true if rhs is equal to self, false otherwise
   */
  bool operator==(const Vehicle &rhs) const;
};

#endif // SRC_VEHICLE_H
