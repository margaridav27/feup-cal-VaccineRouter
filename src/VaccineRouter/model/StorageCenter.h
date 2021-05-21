#ifndef VACCINEROUTER_STORAGECENTER_H
#define VACCINEROUTER_STORAGECENTER_H

#include <string>
#include "Vehicle.h"
#include "../graph/node/Node.h"
#include "Center.h"
#include "ApplicationCenter.h"

class StorageCenter : public Center {
private:
    unsigned int vaccinesToDeliver;
    std::vector<ApplicationCenter *> assignedAC;
    std::vector<Vehicle *> fleet;
    bool optimalState;
public:
    StorageCenter();
    StorageCenter(Node *Node, const std::string& name);
    const std::vector<ApplicationCenter *> &getAssignedAc() const;
    unsigned int getVaccinesToDeliver() const;
    Vehicle* getAvailableVehicle() const;
    const std::vector<Vehicle *> &getFleet();
    void assignAC(ApplicationCenter *ac);
    void setVaccinesToDeliver(unsigned int vaccinesToDeliver);
    void resetPath(std::vector<Node*> oldPath);
    void reset();
    void addVehicle();
    bool removeVehicle(Vehicle *vehicle);
    bool operator==(const StorageCenter *rhs) const;
    bool isOptimalState() const;
    void setOptimalState(bool optimalState);
    bool checkACsVisited();

    ApplicationCenter *findNextNearestAC(Center *startingPoint);

    void unsetOptimalState();

    void setOptimalState();
};


#endif //VACCINEROUTER_STORAGECENTER_H
