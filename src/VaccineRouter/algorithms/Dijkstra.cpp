#include "Dijkstra.h"
#include "../utilities/MutablePriorityQueue.h"


std::vector<Node *> dijkstraShortestPath(Graph graph, Node* orig, Node* dest) {
  for (Node *n: graph.getNodeSet()) {
    n->setPath(nullptr);
    n->setDist(DOUBLE_MAX);
  }

  MutablePriorityQueue minQueue;

  Node* aux = graph.findNode(orig);
  aux->setDist(0);

  minQueue.insert(aux);

  while(!minQueue.empty()){
    aux = minQueue.extractMin();
    for (Edge* edge: aux->getAdj()){
      if (edge->getDest()->getDist() > (aux->getDist() + edge->getWeight())){
        edge->getDest()->setDist(aux->getDist() + edge->getWeight());
        edge->getDest()->setPath(aux);
        if(edge->getDest()->getQueueIndex())
          minQueue.decreaseKey(edge->getDest());
        else {
          minQueue.insert(edge->getDest());
        }
      }
    }
  }
  return getPath(graph,orig,dest);
}

std::vector<Node *> getPath(Graph graph, Node *origin, Node
                                                                 *dest) {
  std::vector<Node*> res;
  Node* aux = graph.findNode(dest);

  while(aux != nullptr){
    res.insert(res.begin(),aux);
    aux = aux->getPath();
  }
  return res;
}
