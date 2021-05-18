#include "AStar.h"

#include <algorithm>
#include "../utilities/MutablePriorityQueue.h"
#include <vector>

//TESTS TO SEE IF STORING IN A VECTOR IS BETTER THAN GOING THROUGH AUXILIARY
// QUEUE
//TODO

std::vector<Node*> AStar(Graph *graph, Node *orig, Node *dest) {
    for (Node *n : graph.getNodeSet()) {
        n->setUnvisited();
        n->setDist(INT_MAX);
        n->setPath(nullptr);
        n->setCost(0);
    }

    orig = graph.findNode(orig);
    dest = graph.findNode(dest);

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
            if (next->getEuclidianDist() == 0)
                queue.insert(next);
            else if (ACost >= next->getCost())
                continue;

            next->setPath(current);
            next->setCost(ACost);
            next->setDist(current->calculateDist(next));
            queue.decreaseKey(next);
        }
    }
    return getPath(graph, dest);
}

std::vector<Node *> getPath(Graph *graph, Node *d){
  Node *aux = graph->findNode(d);
  std::vector<Node *> path;

  while (aux != nullptr) {
    path.insert(path.begin(), aux);
    aux = aux->getPath();
  }
  return path;
}
