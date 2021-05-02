#include "Dijkstra.h"
#include "../utilities/MutablePriorityQueue.h"

void dijkstra(Graph graph, Node* o) {
    for(Node* n : graph.getNodeSet()) {
        n->setDist(DOUBLE_MAX);
    }
    o->setDist(0);
    MutablePriorityQueue q;
    q.insert(o);
    while( ! q.empty() ) {
        auto n = q.extractMin();
        for (auto e : n->getOutgoing()) {
            auto oldDist = e->getDest()->getDist();
            if (relax(n, e->getDest(), e, e->getCapacity() - e->getFlow(), e->getCost())){
                if (oldDist==DOUBLE_MAX)
                    q.insert(e->getDest());
                else
                    q.decreaseKey(e->getDest());
            }
        }
        for (auto e : n->getIncoming()) {
            auto oldDist = e->getOrig()->getDist();
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
