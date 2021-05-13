#ifndef VACCINEROUTER_GRAPHPROCESSOR_H
#define VACCINEROUTER_GRAPHPROCESSOR_H

#include <string>
#include "Graph.h"

Graph * processGraph(std::string chosenCity);

bool processEdges(Graph *graph, std::string chosenCity);

bool processNodes(Graph *graph, std::string chosenCity);

#endif //VACCINEROUTER_GRAPHPROCESSOR_H
