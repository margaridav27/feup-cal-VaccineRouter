#ifndef VACCINEROUTER_GRAPHPROCESSOR_H
#define VACCINEROUTER_GRAPHPROCESSOR_H

#include <string>
#include "Graph.h"

Graph * processGraph(std::string chosenCity);

void processEdges(Graph *graph, std::string chosenCity);

void processNodes(Graph *graph, std::string chosenCity);

#endif //VACCINEROUTER_GRAPHPROCESSOR_H
