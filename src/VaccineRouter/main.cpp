#include "GraphViewer/graphViewer.h"
#include "algorithms/AStar.h"
#include "algorithms/Dijkstra.h"
#include "graph/Graph.h"
#include "graph/GraphProcessor.h"
#include "ui/Interface.h"
#include <iostream>
#include <set>
#include <unordered_set>
Graph CreateTestGraph() {
  Graph myGraph;

  for(int i = 1; i <= 7; i++)
    myGraph.addNode(i, Coordinates(10,5));

  myGraph.addEdge(1, 2, 2);
  myGraph.addEdge(1, 4, 7);
  myGraph.addEdge(2, 4, 3);
  myGraph.addEdge(2, 5, 5);
  myGraph.addEdge(3, 1, 2);
  myGraph.addEdge(3, 6, 5);
  myGraph.addEdge(4, 3, 1);
  myGraph.addEdge(4, 5, 1);
  myGraph.addEdge(4, 6, 6);
  myGraph.addEdge(4, 7, 4);
  myGraph.addEdge(5, 7, 2);
  myGraph.addEdge(6, 4, 3);
  myGraph.addEdge(7, 6, 4);

  return myGraph;
}
int main() {

  // vaccineRouter.calculateRouteSingleSCMultipleAC();
//  vaccineRouter.calculateRouteSingleSCMultipleACWithTW();
 // vaccineRouter.calculateRouteMultipleSCMultipleACWithTW();

  Interface ui;
  ui.initInterface();
}
