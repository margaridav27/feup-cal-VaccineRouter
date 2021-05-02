#ifndef VACCINEROUTER_DIJKSTRA_H
#define VACCINEROUTER_DIJKSTRA_H
#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../graph/Graph.h"


void dijkstra(Graph graph, Node* o);
bool relax(Node *n, Node *w, Edge *e, double residual, double cost);

#endif//VACCINEROUTER_DIJKSTRA_H
