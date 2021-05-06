#ifndef VACCINEROUTER_ASTAR_H
#define VACCINEROUTER_ASTAR_H

#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../graph/Graph.h"

std::vector<Node *> AStar(Graph graph, Node *orig, Node *dest);

std::vector<Node *> getPath(Graph graph, Node *n);

#endif //VACCINEROUTER_ASTAR_H
