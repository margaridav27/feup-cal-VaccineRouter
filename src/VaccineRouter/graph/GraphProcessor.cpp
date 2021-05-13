#include <fstream>
#include <iostream>
#include "GraphProcessor.h"

Graph *processGraph(const std::string& chosenCity) {
    Graph *graph = new Graph();

    if (chosenCity != "espinho" && chosenCity != "porto" && chosenCity != "penafiel") return nullptr;

    if (!processNodes(graph, chosenCity) ||
        !processEdges(graph, chosenCity))
        return nullptr;
    return graph;
}

bool processNodes(Graph *graph, const std::string& chosenCity) {
    std::ifstream istream("../../cityMaps/" + chosenCity + "/" + chosenCity + "_strong_nodes_xy.txt");
    if (!istream.is_open()) {
        std::cerr << "Edges file opening failed.\n";
        return false;
    }

    unsigned int numNodes;
    unsigned int id;
    double x, y;
    char dummy;

    istream >> numNodes;
    for (int i = 0; i < numNodes; ++i) {
        istream >> dummy >> id >> dummy >> x >> dummy >> y >> dummy;
        graph->addNode(id, Coordinates(x, y));
    }

    istream.close();
    return true;
}

bool processEdges(Graph *graph, const std::string& chosenCity) {
    std::ifstream istream("../../cityMaps/" + chosenCity + "/" + chosenCity + "_strong_edges.txt");
    if (!istream.is_open()) {
        std::cerr << "Edges file opening failed.\n";
        return false;
    }

    unsigned int numEdges;
    unsigned int src, dest;
    double weight;
    char dummy;

    istream >> numEdges;
    for (int i = 0; i < numEdges; ++i) {
        istream >> dummy >> src >> dummy >> dest >> dummy;
        Node *s = graph->getNode(src);
        Node *d = graph->getNode(dest);
        if (s == nullptr || d == nullptr) return false; // COMBACK: error message
        weight = s->calculateDist(d);
        graph->addEdge(src, dest, weight);
    }

    istream.close();
    return true;
}
