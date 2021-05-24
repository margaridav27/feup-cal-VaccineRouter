#ifndef VACCINEROUTER_ASTAR_H
#define VACCINEROUTER_ASTAR_H

#include "../graph/Graph.h"
#include "Dijkstra.h"
#include "../graph/edge/Edge.h"
#include "../model/Vehicle.h"

/**
 * A-star algorithm
 * @param graph to implement algorithm on
 * @param orig starting node
 * @param dest ending node
 * @return the path resultant of the algorithm
 */
std::vector<Node *> AStar(Graph *graph, Node *orig, Node *dest);

#endif //VACCINEROUTER_ASTAR_H
