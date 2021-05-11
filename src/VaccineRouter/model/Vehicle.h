#ifndef SRC_VEHICLE_H
#define SRC_VEHICLE_H

#include <queue>
#include <vector>
#include "../graph/node/Node.h"

class Vehicle {
private:
    std::queue<Node *> qPath;
    std::vector<Node *> vPath;
    double speed = 70;
public:
    Vehicle();
    std::queue<Node *> getPath();
    Node *getNextNode();
    void addToPath(Node *n);
    void setSpeed(double speed);
    bool operator==(const Vehicle &rhs) const;
};


#endif //SRC_VEHICLE_H
