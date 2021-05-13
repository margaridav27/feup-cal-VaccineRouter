#include <fstream>
#include <iostream>
#include "GraphProcessor.h"

Graph *processGraph(std::string chosenCity) {
    Graph *graph = new Graph();

    if (chosenCity != "espinho" && chosenCity != "porto" && chosenCity != "penafiel") return nullptr;

    processNodes(graph, chosenCity);
    processEdges(graph, chosenCity);

    return graph;
}

bool processNodes(Graph *graph, std::string chosenCity) {
    std::ifstream istream("cityMaps/" + chosenCity + "/" + chosenCity + "_strong_nodes_xy.txt");
    if (istream.is_open()) {
        std::cerr << "Edges file opening failed.\n";
        return false;
    }

    unsigned int numNodes;
    unsigned int id;
    double x, y;
    char dummy;

    std::cin >> numNodes;
    for (int i = 0; i < numNodes; ++i) {
        std::cin >> dummy >> id >> dummy >> x >> dummy >> y >> dummy;
        graph->addNode(id, Coordinates(x, y));
    }

    istream.close();
    return true;
}

bool processEdges(Graph *graph, std::string chosenCity) {
    std::ifstream istream("cityMaps/" + chosenCity + "/" + chosenCity + "_strong_edges.txt");
    if (istream.is_open()) {
        std::cerr << "Edges file opening failed.\n";
        return false;
    }

    unsigned int numEdges;
    unsigned int src, dest;
    double weight;
    char dummy;

    std::cin >> numEdges;
    for (int i = 0; i < numEdges; ++i) {
        std::cin >> dummy >> src >> dummy >> dest >> dummy;
        Node *s = graph->getNode(src);
        Node *d = graph->getNode(dest);
        if (s == nullptr || d == nullptr) return false; // COMBACK: error message
        weight = s->calculateDist(d);
        graph->addEdge(src, dest, weight);
    }

    istream.close();
    return true;
}
