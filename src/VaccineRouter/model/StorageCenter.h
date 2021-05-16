#ifndef VACCINEROUTER_STORAGECENTER_H
#define VACCINEROUTER_STORAGECENTER_H

#include <string>
#include "Vehicle.h"
#include "../graph/node/Node.h"

class StorageCenter {
private:
    Node *node;
    std::string name;
    unsigned int vaccinesToDeliver;
    std::vector<Node> assignedAC; // COMBACK maybe make this std::vector<unsigned int> or a std::queue<Vechicle>/std::queue<unsigned int>
    std::vector<Vehicle*> fleet;
public:
    StorageCenter(Node *Node, std::string name);
    Node *getNode() const;
    const std::string &getName() const;
    const std::vector<Node> &getAssignedAc() const;
    unsigned int getVaccinesToDeliver() const;
    const std::vector<Vehicle*> &getFleet();
    void setVaccinesToDeliver(unsigned int vaccinesToDeliver);
    void addVehicle(Vehicle *vehicle);
    bool removeVehicle(Vehicle *vehicle);
    bool operator==(const StorageCenter &rhs) const;
};


#endif //VACCINEROUTER_STORAGECENTER_H
