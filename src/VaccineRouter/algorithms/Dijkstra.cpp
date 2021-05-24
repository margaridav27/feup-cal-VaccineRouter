#include "Dijkstra.h"
#include "../utilities/MutablePriorityQueue.h"

/**
 * Dijkstra algorithm
 * @param graph to implement algorithm on
 * @param orig starting node
 * @param dest ending node
 * @return the path resultant of the algorithm
 */
std::vector<Node *> dijkstra(Graph *graph, Node *orig, Node *dest) {
    for (Node *n : graph->getNodeSet()) {
        n->setPath(nullptr);
        n->setDist(DOUBLE_MAX);
    }

    MutablePriorityQueue minQueue;

    Node *aux = graph->findNode(orig->getId());
    aux->setDist(0);

    minQueue.insert(aux);

    while (!minQueue.empty()) {
        aux = minQueue.extractMin();
        for (Edge *edge : aux->getAdj()) {
            if (edge->getDest()->getDist() > (aux->getDist() + edge->getWeight())) {
                edge->getDest()->setDist(aux->getDist() + edge->getWeight());
                edge->getDest()->setPath(aux);
                if (edge->getDest()->getQueueIndex())
                    minQueue.decreaseKey(edge->getDest());
                else {
                    minQueue.insert(edge->getDest());
                }
            }
        }
    }
    return getPath(graph, orig, dest);
}

/**
 * converts the path from o to d in the graph to a vector
 * @param graph to find path
 * @param o starting node
 * @param d ending node
 * @return vector of nodes that corresponds to the path
 */
std::vector<Node *> getPath(Graph *graph, Node *o, Node *d) {
    Node *aux = graph->findNode(d->getId());
    std::vector<Node *> path;

    while (!(aux == o->getPath())) {
        path.insert(path.begin(), aux);
        aux = aux->getPath();
    }
    return path;
}
