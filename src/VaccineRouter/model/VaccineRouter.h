#ifndef VACCINEROUTER_VACCINEROUTER_H
#define VACCINEROUTER_VACCINEROUTER_H

#include "../graph/Graph.h"
#include "../utilities/StringsHashTable.h"
#include "../utilities/Time.h"
#include "ApplicationCenter.h"
#include "StorageCenter.h"

/**
 * class VaccineRouter
 */
class VaccineRouter {
private:
  Graph *graph;
  Time vaccineLifeTime;
  std::string cityName;
  std::vector<StorageCenter *> SCs;
  std::vector<ApplicationCenter *> selectedACs;
  std::vector<ApplicationCenter *> availableACs;

  /**
   *
   * @return the Storage Center that is nearest all of the selected ACs
   */
  StorageCenter *findNearestSC();
  /**
   *
   * @param applicationCenter
   * @return the Storage Center that is nearest the Application Center
   * received as parameter
   */
  StorageCenter *findNearestSC(ApplicationCenter *applicationCenter);
  /**
   * calculates its route
   * @param sc
   * @return true if all assigned Application Centers were included in its
   * route
   */
  bool calculateSCRoute(StorageCenter *sc);

  /**
   *function that handles the Application Centers that weren't assigned to
   * a vehicle in the first attempt
   */
  void handleACsNotVisited();

  /**
   * deletes Application centers that are already handled by a Storage Center
   */
  void deleteDispatchedACs();

public:
  /**
   * contructor
   */
  VaccineRouter();

  /**
   * sets the parameter vaccineLifeTime
   * @param vaccineLifeTime
   */
  VaccineRouter(Time vaccineLifeTime);
  /**
   *
   * @return graph
   */
  Graph *getGraph() const;
  /**
   * sets graph
   * @param graph
   */
  void setGraph(Graph *graph);

  /**
   *sets the parameter cityName to the city chosen by the user
   * @param cityName
   */
  void setCityName(std::string cityName);

  /**
   *
   * @return vector of Storage Centers
   */
  const std::vector<StorageCenter *> &getSCs() const;
  /**
   *
   * @return vector of the Application Centers selected by the user
   */
  const std::vector<ApplicationCenter *> &getSelectedACs() const;

  /**
   *
   * @return vector of all Application Centers available
   */
  const std::vector<ApplicationCenter *> &getAvailableACs() const;

  /**
   *
   * @param node
   * @return 0 if node corresponds to a Storage Center, 1 if Application
   * Center, -1 if regular node
   */
  int getCenter(Node *node);

  /**
   *
   * @param node
   * @return string name of the center that corresponds to the param node
   */
  std::string getCenterName(Node *node);

  /**
   * adds Storage Center sc to the SCs vector
   * @param sc
   */
  void addStorageCenter(StorageCenter *sc);

  /**
   * adds Application Center ac to the SelectedACs vector
   * @param ac
   */
  void selectApplicationCenter(ApplicationCenter *ac);

  /**
   * adds Application Center ac to the avaialableACs vector
   * @param ac
   */
  void addApplicationCenter(ApplicationCenter *ac);

  /**
   * sets up all data according to the mapFilename specified by the user
   * @param mapFilename
   */
  void selectMap(const std::string &mapFilename);

  /**
   * reads SCs from the file and sets SCs up
   * @param mapFilename
   * @return
   */
  bool setUpSCs(const std::string &mapFilename);

  /**
   * reads ACs from the file and sets ACs up
   * @param basicString
   * @return
   */
  bool setUpACS(const std::string &basicString);

  /**
   *
   * @return vaccineLifeTime
   */
  Time getVaccineLifeTime() const;

  /**
   * calculates, with A* algorithm, the route from a SC to an AC
   */
  void calculateRouteSingleSCSingleAC();

  /**
   * calculates, with A* algorithm, the route from a SC to various ACs
   */
  void calculateRouteSingleSCMultipleAC();

  /**
   * calculates, with Dijkstra algorithm, the route from a SC to various
   * ACs, taking in consideration a maximum time window per route
   */
  void calculateRouteSingleSCMultipleACWithTW();

  /**
   * calculates, with Dijkstra algorithm, the route from various SCs to
   * various ACs, taking in consideration a maximum time window per route
   */
  void calculateRouteMultipleSCMultipleACWithTW();

  /**
   * outputs to the user the results of the chosen iteration/algorithm
   */
  void outputDataResults();
};

#endif // VACCINEROUTER_VACCINEROUTER_H
