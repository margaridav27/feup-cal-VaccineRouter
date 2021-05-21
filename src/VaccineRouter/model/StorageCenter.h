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

    void addVehicle();
    bool removeVehicle(Vehicle *vehicle);
    Vehicle* getAvailableVehicle() const;
    const std::vector<Vehicle *> &getFleet();

    const std::vector<ApplicationCenter *> &getAssignedAC() const;
    void assignAC(ApplicationCenter *ac);
    bool checkACsVisited();

    unsigned int getVaccinesToDeliver() const;
    void setVaccinesToDeliver(unsigned int vaccinesToDeliver);

    bool isOptimalState() const;
    void unsetOptimalState();
    void setOptimalState();

    void resetPath(std::vector<Node*> originalPath) const;
    void reset();

    ApplicationCenter *findNextNearestAC(Center *startingPoint) const;

    bool operator==(const StorageCenter *rhs) const;
};


#endif //VACCINEROUTER_STORAGECENTER_H
