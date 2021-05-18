#ifndef SRC_VEHICLE_H
#define SRC_VEHICLE_H

#include "../graph/Graph.h"
#include "../graph/node/Node.h"
#include "../utilities/Time.h"

#include <stack>
#include <vector>

class Vehicle {
private:
    std::stack<Node *> qPath;
    std::vector<Node *> vPath;
    double speed = 70;
    Time pathDuration;
    Time maxPathDuration;

    void addToPath(std::vector<Node *> path);
    Time getPathDuration(std::vector<Node *> path) const;
public:
    Vehicle(Time maxPathDuration);
    std::stack<Node *> getPath();
    Node *getNextNode();
    void setSpeed(double speed);
    bool setVehicleRoute(const std::vector<Node *>& path, bool checkTW);
    bool hasEmptyPath() const;
    bool operator==(const Vehicle &rhs) const;
};


#endif //SRC_VEHICLE_H
