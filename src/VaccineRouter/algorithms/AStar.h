#ifndef VACCINEROUTER_ASTAR_H
#define VACCINEROUTER_ASTAR_H

#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../model/Vehicle.h"

std::vector<Node *> AStar(Graph *graph, Node *orig, Node *dest, Vehicle
                                                                   *vehicle);
std::vector<Node *> getPath(Graph* graph, Node *d);

#endif //VACCINEROUTER_ASTAR_H
