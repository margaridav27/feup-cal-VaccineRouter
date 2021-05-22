#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../graph/node/Node.h"
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

void displayGraph( VaccineRouter *vaccineRouter) {
  GVNodes.clear();
  GVEdges.clear();
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
      GVNode ixOrig = getNodeID(e->getOrig());
      GVNode ixDest = getNodeID(e->getDest());
      GVEdge &edge = gv.addEdge(idEdge++, ixOrig, ixDest,
                                 GraphViewer::Edge::EdgeType::UNDIRECTED);
      GVEdges.insert(std::pair<Edge *, GVEdge>(e, edge));
      // edge.setColor(graphviewer::WHITE);
    }
  }
  gv.join();
}

void displayVehiclesPath(VaccineRouter *vaccineRouter) {
  GVNodes.clear();
  GVEdges.clear();
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
      GVNode ixOrig = getNodeID(e->getOrig());
      GVNode ixDest = getNodeID(e->getDest());
      GVEdge &edge = gv.addEdge(idEdge++, ixOrig, ixDest,
                                GraphViewer::Edge::EdgeType::UNDIRECTED);
      GVEdges.insert(std::pair<Edge *, GVEdge>(e, edge));
      // edge.setColor(graphviewer::WHITE);
    }
  }

  for (StorageCenter *sc : vaccineRouter->getSCs()) {
    for (Vehicle *v : sc->getFleet()) {
      std::map<Node *, GVNode> GVnodes;
      Node *n;
      std::vector<Node *> path = v->getPath();
      for (Node *n : path) {
        GVNode node = getNodeID(n);
        gv.getNode(node.getId()).setColor(GraphViewer::YELLOW);
        Center *center = vaccineRouter->getCenter(n);
        if (center != nullptr)
          gv.getNode(node.getId()).setLabel(center->getName());
      }

      for (int i = 0; i < idNode - 1; i++) {
        GVNode ixOrig = getNodeID(path[i]);
        GVNode ixDest = getNodeID(path[i + 1]);
        GVEdge edge = getEdge(path[i], path[i + 1]);
        gv.getEdge(edge.getId()).setColor(GraphViewer::YELLOW);
        gv.getEdge(edge.getId()).setEdgeType(GraphViewer::Edge::EdgeType::DIRECTED);
      }
    }
  }

  gv.join();
}

/*
GVNode getNodeID(std::map<Node *, GVNode> GVNodes, Node *n) {
    auto itr = GVNodes.find(n);
    if (itr != GVNodes.end())
        return itr->second;
}

void displayGraph(Graph graph) {
    std::map<Node *, GVNode> GVnodes;
    int idEdge = 0;
    int idNode = 0;

    GraphViewer gv;
    gv.setCenter(sf::Vector2f(500, 500));
    gv.createWindow(1000, 1000);
    const std::string &mapFilename =
            "../../cityMaps/porto/porto_full.png";
    gv.setBackground(mapFilename);

    for (Node *n : graph.getNodeSet()) {
        GVNode node =
                gv.addNode(idNode++, sf::Vector2f(n->getCoordinates().getX(),
                                                  n->getCoordinates().getY()));
        GVnodes.insert(std::pair<Node *, GVNode>(n, node));
    }

    for (Node *n : graph.getNodeSet()) {
        for (Edge *e : n->getAdj()) {
            GVNode ixOrig = getNodeID(GVnodes, e->getOrig());
            GVNode ixDest = getNodeID(GVnodes, e->getDest());
            gv.addEdge(idEdge++, ixOrig, ixDest,
                       GraphViewer::Edge::EdgeType::UNDIRECTED);
        }
    }
    gv.join();
}

void displayVehiclesPath(std::vector<StorageCenter *> SCs, std::string city) {
    GraphViewer gv;
    gv.setCenter(sf::Vector2f(1644 / 2, 904 / 2));
    gv.createWindow(1644, 904);
    const std::string &mapFilename =
            "../../cityMaps/" + city + "/" + city + "_full.png";
    int idNode = 0;
    int idEdge = 0;
    int idFirstNodeRoute = 0;

    for (StorageCenter *sc : SCs) {
        for (Vehicle *v : sc->getFleet()) {
            std::map<Node *, GVNode> GVnodes;
            Node *n;
            std::vector<Node *> path = v->getPath();
            idFirstNodeRoute = idNode;

            for (Node *n : path) {

                GVNode node =
                        gv.addNode(idNode++,
sf::Vector2f(n->getCoordinates().getX() - 1644 / 2, n->getCoordinates().getY()
                                                          - 941 / 2));
                //node.setLabel(n.ge)
                //TODO add labels how??
                GVnodes.insert(std::pair<Node *, GVNode>(n, node));
            }

            for (int i = idFirstNodeRoute; i < idNode - 1; i++) {
                GVNode ixOrig = getNodeID(GVnodes, path[i]);
                GVNode ixDest = getNodeID(GVnodes, path[i + 1]);
                gv.addEdge(idEdge++, ixOrig, ixDest,
                           GraphViewer::Edge::EdgeType::DIRECTED);
            }
        }
    }
    gv.setBackground(mapFilename);
    gv.join();
}
*/
