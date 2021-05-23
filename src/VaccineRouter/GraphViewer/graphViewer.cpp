#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../model/StorageCenter.h"
#include "graphViewer.h"

std::map<Node *, GVNode> GVNodes;
std::map<Edge *, GVEdge> GVEdges;

GVNode getNodeID(Node *n) {
    auto itr = GVNodes.find(n);
    if (itr != GVNodes.end())
        return itr->second;
}

GVEdge getEdge(Node *from, Node *to) {
    for (auto e : GVEdges) {
        if (*e.first->getOrig() == *from && e.first->getDest() == to)
            return e.second;
    }
}

void displayGraph(GraphViewer *gv, VaccineRouter *vaccineRouter, int &idNode, int
&idEdge) {
    for (Node *n : vaccineRouter->getGraph()->getNodeSet()) {
        GVNode &node =
                gv->addNode(idNode++, sf::Vector2f(n->getCoordinates().getX(),
                                                   n->getCoordinates().getY()));
        //node.setColor(graphviewer::DARK_GRAY);
        GVNodes.insert(std::pair<Node *, GVNode>(n, node));
    }

    for (Node *n : vaccineRouter->getGraph()->getNodeSet()) {
        for (Edge *e : n->getAdj()) {
            GVNode ixOrig = getNodeID(e->getOrig());
            GVNode ixDest = getNodeID(e->getDest());
            GVEdge &edge = gv->addEdge(idEdge++, ixOrig, ixDest,
                                       GraphViewer::Edge::EdgeType::UNDIRECTED);
            GVEdges.insert(std::pair<Edge *, GVEdge>(e, edge));
            // edge.setColor(graphviewer::WHITE);
        }
    }
}

void displayVehiclesPath(GraphViewer *gv, VaccineRouter *vaccineRouter) {
    int idNode = 0;
    int idEdge = 0;
    displayGraph(gv, vaccineRouter, idNode, idEdge);

    for (StorageCenter *sc : vaccineRouter->getSCs()) {
        for (Vehicle *v : sc->getFleet()) {
            std::map<Node *, GVNode> GVnodes;
            Node *n;
            std::vector<Node *> path = v->getPath();
            for (Node *n : path) {
                GVNode node = getNodeID(n);
                node.setColor(GraphViewer::YELLOW);
                node.setLabel(vaccineRouter->getCenter(n)->getName());
            }

            for (int i = idEdge; i < idNode - 1; i++) {
                GVNode ixOrig = getNodeID(path[i]);
                GVNode ixDest = getNodeID(path[i + 1]);
                GVEdge edge = getEdge(path[i], path[i + 1]);
                edge.setColor(GraphViewer::YELLOW);
                edge.setEdgeType(GraphViewer::Edge::EdgeType::DIRECTED);
            }
        }
    }
}

