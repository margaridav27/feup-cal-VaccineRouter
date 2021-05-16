#include <algorithm>
#include "Tarjan.h"

std::vector<Node *> tarjan(Graph *graph, Node *node) {
    for (Node *n : graph->getNodeSet()) {
        n->setUnvisited();
        n->popFromStack();
    }

    std::vector<Node *> SCCs;
    std::stack<Node *> s;

    tarjanRecursive(graph, node, SCCs, s);

    // extracting only the SCC that matters
    std::vector<Node *> importantSCC;
    for (Node *v : SCCs) {
        if (v == nullptr) {
            for (Node *w : importantSCC) {
                if (w == node) return importantSCC;
            }
            importantSCC.clear();
        } else importantSCC.push_back(v);
    }
    return importantSCC;
}

void tarjanRecursive(Graph *graph, Node *node, std::vector<Node *> &SCCs, std::stack<Node *> &s) {
    node->setVisited();
    node->pushToStack();
    s.push(node);

    for (Edge *e : node->getAdj()) {
        Node *successor = e->getDest();
        // successor has not yet been visited, recurse on it
        if (!successor->wasVisited()) {
            tarjanRecursive(graph, successor, SCCs, s);
            node->setLowlink(std::min(node->getLowlink(), successor->getLowlink()));
            // successor is in stack s and hence in the current SCC
            // if successor is not on stack, then e is an edge pointing to another SCC and must be ignored
        } else if (successor->isOnStack()) {
            node->setLowlink(std::min(node->getLowlink(), successor->getId()));
        }
    }

    // node is the root for the SCC
    if (node->getLowlink() == node->getId()) {
        Node *n;
        do {
            n = s.top();
            s.pop();
            n->setLowlink(n->getId());
            n->setUnvisited();
            n->popFromStack();
            SCCs.push_back(n);
        } while (n != node);
        SCCs.push_back(nullptr); // marks the beggining of a new SCC
    }
}