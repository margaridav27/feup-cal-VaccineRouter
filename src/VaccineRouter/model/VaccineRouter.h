#ifndef VACCINEROUTER_VACCINEROUTER_H
#define VACCINEROUTER_VACCINEROUTER_H

#include "../graph/Graph.h"
#include "../utilities/Time.h"
#include "../utilities/StringsHashTable.h"
#include "StorageCenter.h"
#include "ApplicationCenter.h"

class VaccineRouter {
private:
    Graph *graph;
    Time vaccineLifeTime;
    std::vector<StorageCenter> SCs;
    std::vector<ApplicationCenter> ACs;
public:
    VaccineRouter();
    VaccineRouter(Time vaccineLifeTime);
    const std::vector<StorageCenter> &getSCs() const;
    const std::vector<ApplicationCenter> &getACs() const;
    void addStorageCenter(unsigned int id);
    void addApplicationCenter(unsigned int id);
    void selectMap(const std::string& mapFilename);
    bool setUpSCs(const std::string& mapFilename);
    void processOrders();
    void checkTWOverdue();
    StorageCenter findNearestSC(ApplicationCenter applicationCenter);
    Node *findXCenter();
    Time getVaccineLifeTime() const;
    void calculateRouteSingleSCSingleAC();
    void calculateRouteSingleSCMultipleAC();
    void calculateRouteSingleSCMultipleACWithTW();
    void calculateRouteMultipleSCMultipleACWithTW();
};




#endif //VACCINEROUTER_VACCINEROUTER_H
