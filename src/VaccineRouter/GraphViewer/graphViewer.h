#ifndef VACCINEROUTER_GRAPHVIEWER_H
#define VACCINEROUTER_GRAPHVIEWER_H

#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../graph/node/Node.h"
#include "../graph/edge/Edge.h"
#include "../graph/Graph.h"


using GVNode = GraphViewer::Node;
using GVEdge = GraphViewer::Edge;

GVNode getNodeID(std::map<Node *, GVNode> GVNodes, Node *n);

void displayGraph(Graph graph);


#endif //VACCINEROUTER_GRAPHVIEWER_H
