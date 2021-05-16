#ifndef SRC_VEHICLE_H
#define SRC_VEHICLE_H

#include "../graph/Graph.h"
#include "../graph/node/Node.h"
#include <stack>
#include <vector>

class Vehicle {
private:
    std::stack<Node *> qPath;
    std::vector<Node *> vPath;
    double speed = 70;

    void addToPath(Node *n);
public:
    Vehicle();
    std::stack<Node *> getPath();
    Node *getNextNode();
    void setSpeed(double speed);
    void setVehicleRouteDest(Graph graph, Node *dest);
    void setVehicleRouteOrig(Graph graph, Node *origin);
    bool operator==(const Vehicle &rhs) const;
};


#endif //SRC_VEHICLE_H
