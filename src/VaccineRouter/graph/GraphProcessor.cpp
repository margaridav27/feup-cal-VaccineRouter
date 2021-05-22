#include <fstream>
#include <iostream>
#include "GraphProcessor.h"

Graph *processGraph(const std::string &chosenCity) {
    auto *graph = new Graph();

    if (!processNodes(graph, chosenCity) ||
        !processEdges(graph, chosenCity))
        return nullptr;
    return graph;
}

bool processNodes(Graph *graph, const std::string &chosenCity) {
    std::ifstream istream;
    bool needsProcessing = false;

    // tries to open the strongly connected graph
    istream.open("../../cityMaps/" + chosenCity + "/" + chosenCity + "_strong_nodes_xy.txt");
    if (!istream.is_open()) {

        // if such graph does not exist, tries to open the weakly connected
        istream.open("../../cityMaps/" + chosenCity + "/" + chosenCity + "_full_nodes_xy.txt");
        if (!istream.is_open()) {
            std::cerr << "Edges file opening failed.\n";
            return false;
        } else needsProcessing = true;
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

bool processEdges(Graph *graph, const std::string &chosenCity) {
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
        Node *s = graph->findNode(src);
        Node *d = graph->findNode(dest);
        if (s == nullptr || d == nullptr) return false;
        weight = s->calculateDist(d);
        graph->addEdge(src, dest, weight);
    }

    istream.close();
    return true;
}
