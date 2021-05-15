#ifndef VACCINEROUTER_VACCINEROUTER_H
#define VACCINEROUTER_VACCINEROUTER_H

#include "../graph/Graph.h"
#include "../utilities/Time.h"

class VaccineRouter {
private:
    Graph *graph;
    Time vaccineLifeTime;
    std::hash<std::string> mapsHashName;
public:
    VaccineRouter();
    VaccineRouter(Time vaccineLifeTime);
    const std::hash<std::string> &getMapsHashName() const;
    void loadMap(std::string MapFileName);
    void selectMap(std::string MapFileName);
    void setUpGraph(std::string MapFileName);
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
