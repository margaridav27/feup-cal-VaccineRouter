#ifndef VACCINEROUTER_STORAGECENTER_H
#define VACCINEROUTER_STORAGECENTER_H

#include "../graph/node/Node.h"
#include "ApplicationCenter.h"
#include "Center.h"
#include "Vehicle.h"
#include <string>

/**
 *
 */
class StorageCenter : public Center {
private:
    unsigned int vaccinesToDeliver;
    std::vector<ApplicationCenter *> assignedAC;
    std::vector<Vehicle *> fleet;
    bool optimalState;
    Time vaccineLifeTime;

public:
    /**
     * constructor
     */
    StorageCenter(Time vaccineLifeTime);

    /**
     * constructor
     * @param Node corresponding graph node
     * @param name corresponding name
     */
    StorageCenter(Node *Node, const std::string &name, Time vaccineLifeTime);

    /**
     * adds a default vehicle to this Storage Center's fleet
     */
    void addVehicle();

    /**
     * @return vector of vehicles
     */
    const std::vector<Vehicle *> &getFleet();

    /**
     * @return the last vehicle in the fleet vector which corresponds
     * to the available vehicle
     */
    Vehicle *getAvailableVehicle() const;

    /**
     * @return a vector of Application centers assigned to Storage Center
     */
    const std::vector<ApplicationCenter *> &getAssignedAC() const;

    /**
     * adds an Application Center to the assignedAC vector
     * @param ac
     */
    void assignAC(ApplicationCenter *ac);

    /**
     * used when SC can't reach AC without overdoing the vaccine lifetime
     * removes ac from assigned ACs vector
     * @param ac
     */
    void removeAC(Center *ac);

    /**
     * @return true if all assigned Application Center are visited, false
     * otherwise
     */
    bool checkACsVisited();

    /**
     * @param startingPoint
     * @return the next near Application center, according to its coordinates
     */
    ApplicationCenter *findNextNearestAC(Center *startingPoint) const;

    /**
    * sets the vaccineLifetime variable to vaccineLifetime
    * @param vaccineLifetime
    */
    void setVaccineLifetime(Time vaccineLifetime);

    /**
     * @return vaccines to deliver
     */
    unsigned int getVaccinesToDeliver() const;

    /**
     * increments the number of vaccines to deliver
     * @param vaccinesToDeliver
     */
    void addVaccinesToDeliver(unsigned int vaccinesToDeliver);

    /**
     * @return true if all vehicles in its fleet have complete path, false
     * otherwise
     */
    bool isOptimalState() const;

    /**
     * sets optimalState variable to false, meaning not all of its fleet has
     * complete path
     */
    void unsetOptimalState();

    /**
     * sets optimalState variable to true, meaning that all of its fleet has
     * complete path
     */
    void setOptimalState();

    /**
     * function used in the 4rd iteration to reset the original path, if the
     * attempt to change it failed
     * sets the path to the path received as parameter
     * @param originalPath
     */
    void resetPath(std::vector<Node *> originalPath) const;

    /**
     * function used in the 4rd iteration to remove the previously assigned
     * Application Center
     * removes the last Application center from the assigned vector
     * sets optimal state to false
     */
    void reset();

    /**
     * @param rhs
     * @return true if rhs is equal to self, false otherwise
     */
    bool operator==(const StorageCenter *rhs) const;
};

std::ostream &operator<<(std::ostream &out, StorageCenter *sc);

#endif // VACCINEROUTER_STORAGECENTER_H
