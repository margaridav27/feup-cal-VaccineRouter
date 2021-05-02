#include "Dijkstra.h"
<<<<<<< HEAD
#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../graph/Graph.h"
#include "../utilities/MutablePriorityQueue.h"

#include <limits>

constexpr auto DOUBLE_MAX = std::numeric_limits<double>::max();

void dijkstra(Graph graph, Node* o) {
    for(Node* n : graph.getNodeSet()) {
        n->setDist(DOUBLE_MAX);
    }
    o->setDist(0);
    MutablePriorityQueue<Node > q;
    q.insert(o);
    while( ! q.empty() ) {
        auto n = q.extractMin();
        for (auto e : n->getOutgoing()) {
            auto oldDist = e->getDest()->get;
            if (relax(n, e->getDest(), e, e->getCapacity() - e->getFlow(), e->getCost())){
                if (oldDist==DOUBLE_MAX)
                    q.insert(e->getDest());
                else
                    q.decreaseKey(e->getDest());
            }
        }
        for (auto e : n->getIncoming()) {
            auto oldDist = e->getOrig()->dist;
            if (relax(n, e->getOrig(), e, e->getFlow(), -e->getCost())) {
                if (oldDist == DOUBLE_MAX)
                    q.insert(e->getOrig());
                else
                    q.decreaseKey(e->getOrig());
            }
        }
    }
}

bool relax(Node *n, Node *w, Edge *e, double residual, double cost) {
    if (residual > 0 && n->getDist() + cost < w->getDist()) {
        w->setDist(n->getDist() + cost);
        w->setPath(e);
        return true;
    }
    else
        return false;
}
=======
>>>>>>> 94760f31974e891f177ce4374e0d8a7c5b09a03f
