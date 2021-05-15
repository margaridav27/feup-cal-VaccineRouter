#include "../../lib/GraphViewerCpp/include/graphviewer.h"
#include "graphViewer.h"


GVNode getNodeID(std::map<Node *, GVNode> GVNodes, Node *n) {
    auto itr = GVNodes.find(n);
    if (itr != GVNodes.end())
        return itr->second;
}

GVNode getNodeID(std::vector<GVNode> GVNodes, int index) {
  for(GVNode gvNode: GVNodes){
    if (gvNode.getId() == index)
      return gvNode;
  }
}

void displayGraph(Graph graph) {
    std::map<Node *, GVNode> GVnodes;
    int idEdge = 0;
    int idNode = 0;

    GraphViewer gv;
    gv.setCenter(sf::Vector2f(300, 300));
    gv.createWindow(600, 600);

    for (Node *n: graph.getNodeSet()) {
        GVNode node = gv.addNode(idNode++, sf::Vector2f(n->getCoordinates().getX(), n->getCoordinates().getY()));
        GVnodes.insert(std::pair<Node *, GVNode>(n, node));
    }

    for (Node *n: graph.getNodeSet()) {
        for (Edge *e: n->getAdj()) {
            GVNode ixOrig = getNodeID(GVnodes, e->getOrig());
            GVNode ixDest = getNodeID(GVnodes, e->getDest());
            gv.addEdge(idEdge++, ixOrig, ixDest,
                       GraphViewer::Edge::EdgeType::UNDIRECTED);
        }
    }

    gv.join();

}

void displayVehiclePath(Vehicle vehicle){
  int idNode = 0;
  int idEdge = 0;
  std::vector<GVNode> GVnodes;
  Node *n;

  GraphViewer gv;
  gv.setCenter(sf::Vector2f(300, 300));
  gv.createWindow(600, 600);

  while((n = vehicle.getNextNode()) != nullptr)
    GVNode node = gv.addNode(idNode++, sf::Vector2f(n->getCoordinates().getX(), n->getCoordinates().getY()));

  for (int i = 0; i < idNode - 1; i++){
    GVNode ixOrig = getNodeID(GVnodes,i);
    GVNode ixDest =  getNodeID(GVnodes,i+1);
    gv.addEdge(idEdge++, ixOrig,ixDest,
               GraphViewer::Edge::EdgeType::DIRECTED);
  }

}
