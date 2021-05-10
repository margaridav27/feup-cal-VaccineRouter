#ifndef VACCINEROUTER_TARJAN_H
#define VACCINEROUTER_TARJAN_H

#include <stack>
#include <unordered_set>

#include "../graph/Graph.h"

std::vector<Node *> tarjan(Graph *graph, Node *node);

void tarjanRecursive(Graph *graph, Node *node, std::vector<Node *>& SCCs, std::stack<Node *>& s);


#endif //SRC_TARJAN_H
