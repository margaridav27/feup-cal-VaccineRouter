#ifndef VACCINEROUTER_STORAGECENTER_H
#define VACCINEROUTER_STORAGECENTER_H

#include <string>
#include "Vehicle.h"
#include "../graph/node/Node.h"
#include "Center.h"

class StorageCenter : public Center {
private:
    unsigned int vaccinesToDeliver;
    std::vector<Node> assignedAC;
    std::vector<Vehicle *> fleet;
public:
    StorageCenter();
    StorageCenter(Node *Node, const std::string& name);
    const std::vector<Node> &getAssignedAc() const;
    unsigned int getVaccinesToDeliver() const;
    const std::vector<Vehicle *> &getFleet();
    void setVaccinesToDeliver(unsigned int vaccinesToDeliver);
    void addVehicle(Vehicle *vehicle);
    bool removeVehicle(Vehicle *vehicle);
    bool operator==(const StorageCenter *rhs) const;
};


#endif //VACCINEROUTER_STORAGECENTER_H
