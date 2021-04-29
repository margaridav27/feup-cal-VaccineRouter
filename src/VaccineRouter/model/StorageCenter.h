#ifndef SRC_STORAGECENTER_H
#define SRC_STORAGECENTER_H

#include "Vehicle.h"
#include "../graph/node/Node.h"

class StorageCenter {
private:
    unsigned int locationNodeID;
    unsigned int vaccinesToDeliver;
    std::vector<Node> assignedAC; // COMBACK maybe make this std::vector<unsigned int> or a std::queue<Vechicle>/std::queue<unsigned int>
    std::vector<Vehicle> fleet;
public:
    StorageCenter();
    StorageCenter(unsigned int locationNodeId);

    unsigned int getLocationNodeId() const;

    const std::vector<Node> &getAssignedAc() const;
    unsigned int getVaccinesToDeliver() const;
    void setVaccinesToDeliver(unsigned int vaccinesToDeliver);

    const std::vector<Vehicle> &getFleet() const;
    void addVehicle(Vehicle vehicle);
    bool removeVehicle(Vehicle vehicle);
};


#endif //SRC_STORAGECENTER_H
