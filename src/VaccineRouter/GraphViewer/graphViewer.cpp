#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../model/StorageCenter.h"
#include "graphViewer.h"

std::map<Node *, GVNode> GVNodes;
std::map<Edge *, GVEdge> GVEdges;


GVNode getNodeID(std::map<Node *,GVNode> GVNodes, Node *n) {
  auto itr = GVNodes.find(n);
  if (itr != GVNodes.end())
    return itr->second;
}

void displayACsVisually(VaccineRouter *vaccineRouter) {
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
      gv.getNode(nodeToAlter.getId()).setIcon("../../icons/storage_center.png");
      gv.getNode(nodeToAlter.getId()).setSize(30);

    } else if (i == 1) {
      gv.getNode(nodeToAlter.getId()).setLabel(vaccineRouter->getCenterName(n));
      gv.getNode(nodeToAlter.getId())
          .setIcon("../../icons/application_center.png");
      gv.getNode(nodeToAlter.getId()).setSize(30);
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
  gv.join();
}

void displayVehiclesPath(VaccineRouter *vaccineRouter) {
  std::map<Node *, GVNode> GVNodes;
  std::map<Edge *, GVEdge> GVEdges;

  int idNode = 0;
  int idEdge = 0;
  GraphViewer gv;
  gv.createWindow();

  //Display actual city graph
  for (Node *n : vaccineRouter->getGraph()->getNodeSet()) {
    GVNode &node =
        gv.addNode(idNode++, sf::Vector2f(n->getCoordinates().getX(),
                                          n->getCoordinates().getY()));
    GVNodes.insert(std::pair<Node *, GVNode>(n, node));
    int i = vaccineRouter->getCenter(n);
    GVNode nodeToAlter = getNodeID(GVNodes, n);
    if (i == 0) {
      gv.getNode(nodeToAlter.getId()).setLabel(vaccineRouter->getCenterName(n));
      gv.getNode(nodeToAlter.getId()).setIcon("../../icons/storage_center.png");
      gv.getNode(nodeToAlter.getId()).setSize(30);

    } else if (i == 1) {
      gv.getNode(nodeToAlter.getId()).setLabel(vaccineRouter->getCenterName(n));
      gv.getNode(nodeToAlter.getId())
          .setIcon("../../icons/application_center.png");
      gv.getNode(nodeToAlter.getId()).setSize(30);
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

  //Display Paths
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
        edge.setColor(GraphViewer::GREEN);
      }
    }
  }
  gv.join();
}
