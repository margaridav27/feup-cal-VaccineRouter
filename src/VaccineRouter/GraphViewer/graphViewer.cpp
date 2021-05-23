#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../graph/node/Node.h"
#include "../model/StorageCenter.h"
#include "graphViewer.h"
#include <unistd.h>

GVNode getNodeID(std::map<Node *, GVNode> GVNodes, Node *n) {
  auto it = GVNodes.find(n);
  if (it != GVNodes.end())
    return it->second;
}

GVEdge getEdge(std::map<Edge *, GVEdge> GVEdges, Node *from, Node *to) {
  for (auto e : GVEdges) {
    if (*(e.first->getOrig()) == *from && *(e.first->getDest()) == *to)
      return e.second;
  }
}

void displayGraph(VaccineRouter *vaccineRouter) {
  std::map<Node *, GVNode> GVNodes;
  std::map<Edge *, GVEdge> GVEdges;

  int idNode = 0;
  int idEdge = 0;
  GraphViewer gv;
  gv.createWindow();

  for (Node *n : vaccineRouter->getGraph()->getNodeSet()) {
    GVNode &node =
        gv.addNode(idNode++, sf::Vector2f(n->getCoordinates().getX(),
                                          n->getCoordinates().getY()));
    // node.setColor(graphviewer::DARK_GRAY);
    GVNodes.insert(std::pair<Node *, GVNode>(n, node));
  }

  for (Node *n : vaccineRouter->getGraph()->getNodeSet()) {
    for (Edge *e : n->getAdj()) {
      GVNode ixOrig = getNodeID(GVNodes, e->getOrig());
      GVNode ixDest = getNodeID(GVNodes, e->getDest());
      GVEdge &edge = gv.addEdge(idEdge++, ixOrig, ixDest,
                                GraphViewer::Edge::EdgeType::UNDIRECTED);
      GVEdges.insert(std::pair<Edge *, GVEdge>(e, edge));
      // edge.setColor(graphviewer::WHITE);
    }
  }
  gv.join();
}

void displayVehiclesPath(VaccineRouter *vaccineRouter) {
  std::map<Node *, GVNode> GVNodes;
  std::map<Edge *, GVEdge> GVEdges;

  int idNode = 0;
  int idEdge = 0;
  GraphViewer gv;
  gv.createWindow();

  for (Node *n : vaccineRouter->getGraph()->getNodeSet()) {
    GVNode &node =
        gv.addNode(idNode++, sf::Vector2f(n->getCoordinates().getX(),
                                          n->getCoordinates().getY()));
    GVNodes.insert(std::pair<Node *, GVNode>(n, node));
    int i = vaccineRouter->getCenter(n);
    GVNode nodeToAlter = getNodeID(GVNodes, n);
    if (i == 0) {
      gv.getNode(nodeToAlter.getId()).setLabel(vaccineRouter->getCenterName(n));
      gv.getNode(nodeToAlter.getId()).setColor(GraphViewer::BLUE);
    } else if (i == 1) {
      gv.getNode(nodeToAlter.getId()).setLabel(vaccineRouter->getCenterName(n));
      gv.getNode(nodeToAlter.getId()).setColor(GraphViewer::RED);
    }
  }

  for (Node *n : vaccineRouter->getGraph()->getNodeSet()) {
    for (Edge *e : n->getAdj()) {
      GVNode ixOrig = getNodeID(GVNodes, e->getOrig());
      GVNode ixDest = getNodeID(GVNodes, e->getDest());
      GVEdge &edge = gv.addEdge(idEdge++, ixOrig, ixDest,
                                GraphViewer::Edge::EdgeType::UNDIRECTED);
    }
  }
int lastID = idNode;
  for (StorageCenter *sc : vaccineRouter->getSCs()) {
    for (Vehicle *v : sc->getFleet()) {
      std::map<Node *, GVNode> GVnodes;
      Node *n;
      std::vector<Node *> path = v->getPath();
      lastID = idNode;

      for (Node *n : path) {

        GVNode node =
            gv.addNode(idNode++, sf::Vector2f(n->getCoordinates().getX(),
                                              n->getCoordinates().getY()));
        GVnodes.insert(std::pair<Node *, GVNode>(n, node));
      }

      for (int i = lastID; i < idNode - 1; i++) {
        GVNode &ixOrig = gv.getNode(i);
        GVNode &ixDest = gv.getNode(i+1);
        GVEdge &edge = gv.addEdge(idEdge++, ixOrig, ixDest,
                   GraphViewer::Edge::EdgeType::UNDIRECTED);
        edge.setThickness(15);
        edge.setColor(GraphViewer::YELLOW);
      }
    }
  }
  gv.join();

}
