#include "../../lib/GraphViewerCpp/include/graphviewer.h"
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
