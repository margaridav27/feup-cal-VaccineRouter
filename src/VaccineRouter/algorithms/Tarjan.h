#ifndef VACCINEROUTER_TARJAN_H
#define VACCINEROUTER_TARJAN_H

#include "../graph/Graph.h"

std::vector<Node *> tarjan(Graph *graph, Node *node);

std::vector<Node  *> tarjanRecursive(Graph *graph, Node *node);


#endif //SRC_TARJAN_H
