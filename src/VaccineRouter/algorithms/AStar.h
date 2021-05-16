#ifndef VACCINEROUTER_ASTAR_H
#define VACCINEROUTER_ASTAR_H

#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../model/Vehicle.h"

void AStar(Graph graph, Node *orig, Node *dest, Vehicle *vehicle);

#endif //VACCINEROUTER_ASTAR_H
