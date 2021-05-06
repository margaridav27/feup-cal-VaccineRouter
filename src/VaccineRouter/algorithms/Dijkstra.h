#ifndef VACCINEROUTER_DIJKSTRA_H
#define VACCINEROUTER_DIJKSTRA_H
#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../graph/Graph.h"


std::vector<Node*> dijkstra(Graph graph, Node* o);
std::vector<Node *> getPath(Graph graph, Node *origin, Node *dest);

#endif//VACCINEROUTER_DIJKSTRA_H
