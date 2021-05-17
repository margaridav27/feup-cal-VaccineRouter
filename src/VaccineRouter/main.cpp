#include "GraphViewer/graphViewer.h"
#include "algorithms/AStar.h"
#include "algorithms/Dijkstra.h"
#include "graph/Graph.h"
#include "graph/GraphProcessor.h"
#include "ui/Interface.h"
#include <iostream>
#include <set>
#include <unordered_set>

Graph* CreateTestGraph() {
    Graph *myGraph = new Graph();

    myGraph->addNode(1, Coordinates(1,2));
    myGraph->addNode(2, Coordinates(60,60));
    myGraph->addNode(3, Coordinates(15,40));
    myGraph->addNode(4, Coordinates(1,20));
    myGraph->addNode(5, Coordinates(3,3));
    myGraph->addNode(6, Coordinates(20,20));
    myGraph->addNode(7, Coordinates(10,60));

    myGraph->addEdge(1, 5, 2);
    myGraph->addEdge(1, 4, 7);
    myGraph->addEdge(2, 4, 3);
    myGraph->addEdge(2, 5, 5);
    myGraph->addEdge(3, 7, 2);
    myGraph->addEdge(3, 4, 5);
    myGraph->addEdge(4, 7, 1);
    myGraph->addEdge(4, 3, 1);
    myGraph->addEdge(5, 6, 6);
    myGraph->addEdge(5, 4, 4);
    myGraph->addEdge(5, 7, 2);
    myGraph->addEdge(6, 7, 3);
    myGraph->addEdge(7, 6, 4);

    return myGraph;
}
int main() {
    VaccineRouter vaccineRouter;
    vaccineRouter.setGraph(CreateTestGraph());

    StorageCenter sc1(new Node(1, Coordinates(1,2)),"Storage Center 1");
    StorageCenter sc2(new Node(2, Coordinates(60,60)),"Storage Center 2");

    ApplicationCenter ap1(new Node(5, Coordinates(3,3)),"Application Center1");
    ApplicationCenter ap2(new Node(6, Coordinates(20,20)),"Application Center3");
    ApplicationCenter ap3(new Node(7, Coordinates(10,603)),"Application Center4");
    ApplicationCenter ap4(new Node(4, Coordinates(1,20)),"Application Center4");

    vaccineRouter.addStorageCenter(&sc1);
    vaccineRouter.addStorageCenter(&sc2);
    vaccineRouter.addApplicationCenter(&ap1);
    vaccineRouter.addApplicationCenter(&ap2);
    vaccineRouter.addApplicationCenter(&ap3);
    vaccineRouter.addApplicationCenter(&ap4);

    vaccineRouter.calculateRouteSingleSCMultipleAC();



    //Interface ui;
    //ui.initInterface();
}
