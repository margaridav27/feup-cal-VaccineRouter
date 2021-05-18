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

    void addToPath(Node *n);
public:
    Vehicle();
    std::stack<Node *> getPath();
    Node *getNextNode();
    Time getPathDuration();
    void setSpeed(double speed);
    void setVehicleRoute(Graph graph, Node *dest);
    bool hasEmptyPath() const;
    bool operator==(const Vehicle &rhs) const;
};


#endif //SRC_VEHICLE_H
