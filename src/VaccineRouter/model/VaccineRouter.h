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
    std::string cityName;
    std::vector<StorageCenter *> SCs;
    std::vector<ApplicationCenter *> selectedACs;
    std::vector<ApplicationCenter *> availableACs;

    StorageCenter *findNearestSC();
    StorageCenter *findNearestSC(ApplicationCenter *applicationCenter);
    bool calculateSCRoute(StorageCenter *sc);
    void handleACsNotVisited();
    void deleteDispatchedACs();
public:
    VaccineRouter();
    VaccineRouter(Time vaccineLifeTime);

    Graph *getGraph() const;
    void setGraph(Graph *graph);
    void setCityName(std::string cityName);

    const std::vector<StorageCenter *> &getSCs() const;
    const std::vector<ApplicationCenter *> &getSelectedACs() const;
    const std::vector<ApplicationCenter *> &getAvailableACs() const;

    int getCenter(Node *node);
    std::string getCenterName(Node *node);

    void addStorageCenter(StorageCenter *sc);
    void selectApplicationCenter(ApplicationCenter *ac);
    void addApplicationCenter(ApplicationCenter *ac);

    void selectMap(const std::string &mapFilename);
    bool setUpSCs(const std::string &mapFilename);

    Time getVaccineLifeTime() const;

    void calculateRouteSingleSCSingleAC();
    void calculateRouteSingleSCMultipleAC();
    void calculateRouteSingleSCMultipleACWithTW();
    void calculateRouteMultipleSCMultipleACWithTW();
    bool setUpACS(const std::string &basicString);
};


#endif //VACCINEROUTER_VACCINEROUTER_H
