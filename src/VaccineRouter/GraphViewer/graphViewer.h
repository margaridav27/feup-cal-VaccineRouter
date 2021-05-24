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

GVNode getNodeID(Node *n);

void displayACsVisually(VaccineRouter *vaccineRouter);

GVNode getNodeID(std::map<Node*, GVNode> GVNodes, Node * n);

void displayVehiclesPath(VaccineRouter *vaccineRouter);


#endif //VACCINEROUTER_GRAPHVIEWER_H
