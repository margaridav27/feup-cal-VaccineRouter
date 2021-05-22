#ifndef VACCINEROUTER_GRAPHPROCESSOR_H
#define VACCINEROUTER_GRAPHPROCESSOR_H

#include <string>
#include "Graph.h"

Graph * processGraph(const std::string& chosenCity, bool strong);

bool processEdges(Graph *graph, const std::string& chosenCity, bool strong);

bool processNodes(Graph *graph, const std::string& chosenCity, bool strong);

#endif //VACCINEROUTER_GRAPHPROCESSOR_H
