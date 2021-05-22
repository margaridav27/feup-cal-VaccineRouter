#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "../model/StorageCenter.h"
#include "graphViewer.h"

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
  gv.setCenter(sf::Vector2f(1644/2, 904/2));
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
            gv.addNode(idNode++, sf::Vector2f(n->getCoordinates().getX()-
                                                  1644/2,
                                              n->getCoordinates().getY()
                                                  -941/2));
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
