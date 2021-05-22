#ifndef VACCINEROUTER_GRAPHVIEWER_H
#define VACCINEROUTER_GRAPHVIEWER_H

#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../graph/node/Node.h"
#include "../model/Vehicle.h"
#include "../model/StorageCenter.h"


using GVNode = GraphViewer::Node;
using GVEdge = GraphViewer::Edge;

GVNode getNodeID(std::map<Node *, GVNode> GVNodes, Node *n);

GVNode getNodeID(std::vector<GVNode> GVNodes, int index);

void displayGraph(Graph graph);

void displayVehiclesPath(std::vector<StorageCenter *> SCs, std::string city);


#endif //VACCINEROUTER_GRAPHVIEWER_H
