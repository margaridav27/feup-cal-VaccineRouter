#ifndef VACCINEROUTER_DIJKSTRA_H
#define VACCINEROUTER_DIJKSTRA_H

#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../model/Vehicle.h"

std::vector<Node *> dijkstra(Graph *graph, Node *o, Node *d);

std::vector<Node *> getPath(Graph *graph, Node *o, Node *d);

#endif//VACCINEROUTER_DIJKSTRA_H
