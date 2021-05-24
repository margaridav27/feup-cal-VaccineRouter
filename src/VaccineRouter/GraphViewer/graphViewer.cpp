#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../model/StorageCenter.h"
#include "graphViewer.h"

std::map<Node *, GVNode> GVNodes;
std::map<Edge *, GVEdge> GVEdges;

/**
 *
 * @param GVNodes
 * @param n
 * @return GVNode correspondant to the node n
 */
GVNode getNodeID(std::map<Node *,GVNode> GVNodes, Node *n) {
  auto itr = GVNodes.find(n);
  if (itr != GVNodes.end())
    return itr->second;
}


void displayConnectivityAnalisis(Graph *graph, Graph *strongGraph){
  std::map<Node *, GVNode> GVNodes;
  std::map<Edge *, GVEdge> GVEdges;

  int idNode = 0;
  int idEdge = 0;
  GraphViewer gv;
  gv.createWindow();

  for (Node *n :graph->getNodeSet()) {
    GVNode &node =
        gv.addNode(idNode++, sf::Vector2f(n->getCoordinates().getX(),
                                          n->getCoordinates().getY()));
    GVNodes.insert(std::pair<Node *, GVNode>(n, node));
  }
  for (Node *n : graph->getNodeSet()) {
    for (Edge *e : n->getAdj()) {
      GVNode ixOrig = getNodeID(GVNodes, e->getOrig());
      GVNode ixDest = getNodeID(GVNodes, e->getDest());
      GVEdge &edge = gv.addEdge(idEdge++, ixOrig, ixDest,
                                GraphViewer::Edge::EdgeType::UNDIRECTED);
    }
  }
  int xShift = 1000;
  for (Node *n :strongGraph->getNodeSet()) {
    GVNode &node =
        gv.addNode(idNode++, sf::Vector2f(n->getCoordinates().getX() + xShift,
                                          n->getCoordinates().getY()));
    GVNodes.insert(std::pair<Node *, GVNode>(n, node));
  }
  for (Node *n : strongGraph->getNodeSet()) {
    for (Edge *e : n->getAdj()) {
      GVNode ixOrig = getNodeID(GVNodes, e->getOrig());
      GVNode ixDest = getNodeID(GVNodes, e->getDest());
      GVEdge &edge = gv.addEdge(idEdge++, ixOrig, ixDest,
                                GraphViewer::Edge::EdgeType::UNDIRECTED);
    }
  }

  gv.join();
}
/**
 * displays the city graph and highlights the Application and Storage Centers
 * @param vaccineRouter
 */
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
      gv.getNode(nodeToAlter.getId()).setSize(40);

    } else if (i == 1) {
      gv.getNode(nodeToAlter.getId()).setLabel(vaccineRouter->getCenterName(n));
      gv.getNode(nodeToAlter.getId())
          .setIcon("../../icons/application_center.png");
      gv.getNode(nodeToAlter.getId()).setSize(40);
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

/**
 * displays the calculated route visually
 * @param vaccineRouter
 */
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
      gv.getNode(nodeToAlter.getId()).setSize(40);

    } else if (i == 1) {
      gv.getNode(nodeToAlter.getId()).setLabel(vaccineRouter->getCenterName(n));
      gv.getNode(nodeToAlter.getId())
          .setIcon("../../icons/application_center.png");
      gv.getNode(nodeToAlter.getId()).setSize(40);
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

  std::vector<sf::Color> color= {GraphViewer::GREEN, GraphViewer::BLUE,
      GraphViewer::PINK, GraphViewer::YELLOW, GraphViewer::CYAN,
                       GraphViewer::ORANGE, GraphViewer::MAGENTA,
                       GraphViewer::RED};
  int colorix = 0;
  for (StorageCenter *sc : vaccineRouter->getSCs()) {

    double thickness = 15;
    for (Vehicle *v : sc->getFleet()) {
      std::map<Node *, GVNode> GVnodes;
      std::vector<Node *> path = v->getPath();
      if (path.empty()) continue;
      for (int i = 0; i < path.size()-1; i++){
        GVNode &node1 =
            gv.addNode(idNode++, sf::Vector2f(path[i]->getCoordinates().getX(),
                                              path[i]->getCoordinates().getY()));
        GVNode &node2 =
            gv.addNode(idNode++, sf::Vector2f(path[i + 1]->getCoordinates()
                                                  .getX(),
                                              path[i + 1]->getCoordinates().getY
                                              ()));
        GVnodes.insert(std::pair<Node *, GVNode>(path[i], node1));
        GVnodes.insert(std::pair<Node *, GVNode>(path[i+1], node2));

        GVEdge &edge = gv.addEdge(idEdge++, node1, node2,
                                  GraphViewer::Edge::EdgeType::UNDIRECTED);
        edge.setThickness(thickness);
        edge.setColor(color[colorix % color.size()]);
      }
      colorix++;
      thickness += 5;

    }
  }
  gv.join();
}
