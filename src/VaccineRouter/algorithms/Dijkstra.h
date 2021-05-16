#ifndef VACCINEROUTER_DIJKSTRA_H
#define VACCINEROUTER_DIJKSTRA_H

#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../model/Vehicle.h"

void dijkstra(Graph graph, Node *o, Node *d, Vehicle *vehicle);

#endif//VACCINEROUTER_DIJKSTRA_H
