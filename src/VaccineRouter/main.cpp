#include "GraphViewer/graphViewer.h"
#include "algorithms/AStar.h"
#include "algorithms/Dijkstra.h"
#include "graph/Graph.h"
#include "graph/GraphProcessor.h"
#include "ui/Interface.h"
#include <iostream>
#include <set>
#include <unordered_set>

Graph *CreateTestGraph() {
  Graph *myGraph = new Graph();

  myGraph->addNode(1, Coordinates(5, 5));
  myGraph->addNode(2, Coordinates(10, 5));
  myGraph->addNode(3, Coordinates(30, 5));
  myGraph->addNode(4, Coordinates(30, 10));
  myGraph->addNode(5, Coordinates(20, 10));
  myGraph->addNode(6, Coordinates(20, 15));
  myGraph->addNode(7, Coordinates(30, 15));
  myGraph->addNode(8, Coordinates(40, 30));

  myGraph->addEdge(1, 2, 2);
  myGraph->addEdge(2, 3, 7);
  myGraph->addEdge(3, 4, 3);
  myGraph->addEdge(4, 5, 5);
  myGraph->addEdge(5, 6, 2);
  myGraph->addEdge(7, 6, 5);
  myGraph->addEdge(8, 7, 1);


  return myGraph;
}
int main() {

  VaccineRouter vaccineRouter;
  vaccineRouter.setGraph(CreateTestGraph());

  StorageCenter sc1(new Node(1, Coordinates(5, 5)), "Storage Center 1");
  StorageCenter sc2(new Node(2, Coordinates(40, 30)), "Storage Center 2");

  ApplicationCenter ap1(new Node(4, Coordinates(25, 5)), "Application "
                                                          "Center1");
  ApplicationCenter ap2(new Node(5, Coordinates(20, 10)),
                        "Application Center3");
  ApplicationCenter ap3(new Node(6, Coordinates(20, 15)),
                        "Application Center4");

  vaccineRouter.addStorageCenter(&sc1);
  vaccineRouter.addStorageCenter(&sc2);
  vaccineRouter.addApplicationCenter(&ap1);
  vaccineRouter.addApplicationCenter(&ap2);
  vaccineRouter.addApplicationCenter(&ap3);

  // vaccineRouter.calculateRouteSingleSCMultipleAC();

//  vaccineRouter.calculateRouteSingleSCMultipleACWithTW();
 // vaccineRouter.calculateRouteMultipleSCMultipleACWithTW();

   Interface ui;
  ui.initInterface();
}
