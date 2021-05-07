#include <stack>
#include <set>
#include "Tarjan.h"

std::set<Node *> tarjan(Graph *graph, Node *node) {
    for (Node *node : graph->getNodeSet()) node->setUnvisited();

    std::set<Node *> scc;
    std::stack<Node *> s;

    s.push(node);
    node->pushToStack();

    for (Edge *e : node->getAdj()) {
        Node *successor = e->getDest();

        // successor has not yet been visited, recurse on it
        if (!successor->wasVisited()) {
            tarjan(graph, successor);
            node->setLowlink(std::min(node->getLowlink(), successor->getLowlink()));

        // successor is in stack s and hence in the current scc
        // if successor is not on stack, then e is an edge pointing to another scc and must be ignored
        } else if (successor->isOnStack()) {
            node->setLowlink(std::min(node->getLowlink(), successor->getId()));
        }
    }

    // node is the root for the scc
    if (node->getLowlink() == node->getId()) {
        Node *n;
        do {
            n = s.top();
            s.pop();

            scc.insert(n);

            // reset lowlink and onStack node attributes
            n->setLowlink(n->getId());
            n->popFromStack();
        } while (n == node);
    }

    return scc;
}
