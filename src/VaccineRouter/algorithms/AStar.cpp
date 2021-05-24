#include "AStar.h"

#include "../utilities/MutablePriorityQueue.h"
#include <algorithm>
#include <vector>


std::vector<Node *> AStar(Graph *graph, Node *orig, Node *dest) {
    for (Node *n : graph->getNodeSet()) {
        n->setUnvisited();
        n->setDist(DOUBLE_MAX);
        n->setPath(nullptr);
        n->setCost(0);
    }

    orig = graph->findNode(orig->getId());
    dest = graph->findNode(dest->getId());

    MutablePriorityQueue queue;
    queue.insert(orig);
    orig->setDist(orig->calculateDist(dest));

    while (!queue.empty()) {
        Node *current = queue.extractMin();
        if (current == dest)
            break;
        current->setVisited();

        for (Edge *e : current->getAdj()) {
            Node *next = e->getDest();
            if (next->wasVisited())
                continue;

            double ACost = current->getCost() + e->getCost();
            if (next->getDist() == DOUBLE_MAX)
                queue.insert(next);
            else if (ACost >= next->getCost())
                continue;

            next->setPath(current);
            next->setCost(ACost);
            next->setDist(current->calculateDist(next));
            queue.decreaseKey(next);
        }
    }
    return getPath(graph, orig, dest);
}
