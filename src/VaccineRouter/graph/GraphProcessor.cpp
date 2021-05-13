#include "GraphProcessor.h"

Graph * processGraph(std::string chosenCity) {
    Graph *graph = new Graph();

    processNodes(graph, chosenCity);
    processEdges(graph, chosenCity);

    return graph;
}

void processEdges(Graph *graph, std::string chosenCity) {
    std::string nodesPath = R"(..\..\..\cityMaps\)" + chosenCity + R"("\")" + chosenCity + "_strong_nodes_xy.txt";
}

void processNodes(Graph *graph, std::string chosenCity) {
    std::string edgesPath = R"(..\..\..\cityMaps\)" + chosenCity + R"("\")" + chosenCity + "_strong_edges.txt";

}
