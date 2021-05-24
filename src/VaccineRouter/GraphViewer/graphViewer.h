#ifndef VACCINEROUTER_GRAPHVIEWER_H
#define VACCINEROUTER_GRAPHVIEWER_H

#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../graph/node/Node.h"
#include "../model/Vehicle.h"
#include "../model/StorageCenter.h"
#include "../model/VaccineRouter.h"

using GVNode = GraphViewer::Node;
using GVEdge = GraphViewer::Edge;

/**
 * displays the city graph and highlights the Application and Storage Centers
 * @param vaccineRouter
 */
void displayACsVisually(VaccineRouter *vaccineRouter);

/**
 * displays pre-processed graph and pos-processed graph
 * processing consists in removing all unattainable nodes from the graph,
 * creating a strongly connected graph
 * @param graph
 * @param strongGraph
 */
void displayConnectivityAnalysis(Graph *graph, Graph *strongGraph);

/**
 * @param GVNodes
 * @param n
 * @return GVNode correspondent to the node n
 */
GVNode getNodeID(std::map<Node *, GVNode> GVNodes, Node *n);

/**
 * displays the calculated route visually
 * @param vaccineRouter
 */
void displayVehiclesPath(VaccineRouter *vaccineRouter);


#endif //VACCINEROUTER_GRAPHVIEWER_H
