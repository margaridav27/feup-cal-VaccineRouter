#include "Dijkstra.h"
#include "../utilities/MutablePriorityQueue.h"

std::vector<Node *> dijkstra(Graph *graph, Node *orig, Node *dest) {
  for (Node *n : graph->getNodeSet()) {
    n->setPath(nullptr);
    n->setDist(DOUBLE_MAX);
  }

  MutablePriorityQueue minQueue;

  Node *aux = graph->findNode(orig);
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

std::vector<Node *> getPath(Graph *graph,Node *o, Node *d) {
  Node *aux = graph->findNode(d);
  std::vector<Node *> path;

  while (!(aux == o->getPath())) {
    path.insert(path.begin(), aux);
    aux = aux->getPath();
  }
  return path;
}
