#ifndef VACCINEROUTER_VACCINEROUTER_H
#define VACCINEROUTER_VACCINEROUTER_H

#include "../graph/Graph.h"
#include "../utilities/Time.h"

class VaccineRouter {
private:
    Graph *graph;
    Time vaccineLifeTime;
    std::hash<std::string> MapsHashName;
public:
    VaccineRouter();
    VaccineRouter(Time vaccineLifeTime);
    void loadMap(std::string MapFileName);
    void setUpGraph(std::string MapFileName);
    void selectGraph(std::string MapFileName);
    void processGraph();
    void processOrders();
    void checkTWOverdue();
    void findNearestSC();
    void findSC();
    Time getVaccineLifeTime() const;
    void calculateRouteSingleSCSingleAC();
    void calculateRouteSingleSCMultipleAC();
    void calculateRouteSingleSCMultipleACWithTW();
    void calculateRouteMultipleSCMultipleACWithTW();
};


#endif //VACCINEROUTER_VACCINEROUTER_H
