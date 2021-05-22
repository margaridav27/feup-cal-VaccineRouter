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

GVNode getNodeID( int index);

void displayGraph(GraphViewer *gv, VaccineRouter *vaccineRouter, int &idNode, int &idEdge);

void displayVehiclesPath(GraphViewer *gv, VaccineRouter *vaccineRouter);


#endif //VACCINEROUTER_GRAPHVIEWER_H
