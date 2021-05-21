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
    std::vector<StorageCenter *> SCs;
    std::vector<ApplicationCenter *> ACs;

    StorageCenter *findNearestSC();
    StorageCenter *findNearestSC(ApplicationCenter *applicationCenter);
    bool calculateSCRoute(StorageCenter *sc);
    void handleACsNotVisited();
public:
    VaccineRouter();
    VaccineRouter(Time vaccineLifeTime);

    Graph *getGraph() const;
    void setGraph(Graph *graph);

    void addStorageCenter(StorageCenter *sc);
    void addApplicationCenter(ApplicationCenter *ac);

    void selectMap(const std::string &mapFilename);
    bool setUpSCs(const std::string &mapFilename);

    void processOrders();
    Time getVaccineLifeTime() const;

    void calculateRouteSingleSCSingleAC();
    void calculateRouteSingleSCMultipleAC();
    void calculateRouteSingleSCMultipleACWithTW();
    void calculateRouteMultipleSCMultipleACWithTW();
};


#endif //VACCINEROUTER_VACCINEROUTER_H
