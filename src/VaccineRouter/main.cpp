#include <iostream>
#include <set>
#include <unordered_set>
#include "GraphViewer/graphViewer.h"
#include "graph/Graph.h"
#include "algorithms/Tarjan.h"

int main() {
    Graph *graph = new Graph();
    graph->addNode(0, Coordinates(0, 1));
    graph->addNode(1, Coordinates(1, 1));
    graph->addNode(2, Coordinates(1, 0));
    graph->addNode(3, Coordinates(0, 0));
    graph->addNode(4, Coordinates(2, 0));
    graph->addNode(5, Coordinates(2.5, 1));
    graph->addNode(6, Coordinates(3, 0));
    graph->addNode(7, Coordinates(4, 0));

    graph->addEdge(3, 0, 1);
    graph->addEdge(0, 1, 1);
    graph->addEdge(1, 2, 1);
    graph->addEdge(2, 3, 1);
    graph->addEdge(2, 4, 1);
    graph->addEdge(4, 5, 1);
    graph->addEdge(5, 6, 1);
    graph->addEdge(6, 4, 1);
    graph->addEdge(6, 7, 1);

    std::vector<Node *> res = tarjan(graph, graph->getNode(0));
    if (res.empty()) {
        std::cout << "empty set was returned!";
        return 1;
    }
    std::cout << "scc: ";
    for (auto node : res) {
        std::cout << node->getId() << " ";
    }
    std::cout << '\n';

    return 0;
}
