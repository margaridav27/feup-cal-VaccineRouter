#ifndef VACCINEROUTER_DIJKSTRA_H
#define VACCINEROUTER_DIJKSTRA_H

#include "../graph/Graph.h"
#include "../graph/edge/Edge.h"
#include "../model/Vehicle.h"

/**
 * Dijkstra algorithm
 * @param graph to implement algorithm on
 * @param orig starting node
 * @param dest ending node
 * @return the path resultant of the algorithm
 */
std::vector<Node *> dijkstra(Graph *graph, Node *o, Node *d);

/**
 * converts the path from o to d in the graph to a vector
 * @param graph to find path
 * @param o starting node
 * @param d ending node
 * @return vector of nodes that corresponds to the path
 */
std::vector<Node *> getPath(Graph *graph, Node *o, Node *d);

#endif//VACCINEROUTER_DIJKSTRA_H
