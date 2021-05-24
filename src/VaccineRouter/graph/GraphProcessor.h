#ifndef VACCINEROUTER_GRAPHPROCESSOR_H
#define VACCINEROUTER_GRAPHPROCESSOR_H

#include <string>
#include "Graph.h"

/**
 * creates a graph from a file input
 * @param chosenCity name of the cityFile to read
 * @param strong
 * @return the created graph
 */
Graph * processGraph(const std::string& chosenCity, bool strong);

/**
 * inserts read edged to graph graph
 * @param graph
 * @param chosenCity  name of the cityFile to read
 * @param strong
 * @return true if processing went OK, false otherwise
 */
bool processEdges(Graph *graph, const std::string& chosenCity, bool strong);

/**
 * inserts read nodes to graph graph
 * @param graph
 * @param chosenCity name of the cityFile to read
 * @param strong
 * @return true if processing went OK, false otherwise
 */
bool processNodes(Graph *graph, const std::string& chosenCity, bool strong);

#endif //VACCINEROUTER_GRAPHPROCESSOR_H
