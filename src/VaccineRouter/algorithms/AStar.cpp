#include "AStar.h"

#include <queue>
#include <vector>
#include <algorithm>

//TESTS TO SEE IF STORING IN A VECTOR IS BETTER THAN GOING THROUGH AUXILIARY
// QUEUE
//TODO

std::vector<Node *> AStar(Graph graph, Node *orig, Node *dest) {
    std::queue<Node *> openQueue;
    std::queue<Node *> closedQueue;
    std::vector<Node *> closedAux;
    std::vector<Node *> openAux;


    for (Node *n: graph.getNodeSet()) {
        n->setEuclidianDist(0);
    }
    openQueue.push(orig);
    openAux.push_back(orig);

    while (!openQueue.empty()) {
        Node *aux = openQueue.front();
        openQueue.pop();
        closedAux.push_back(aux);
        closedQueue.push(aux);
        if (aux == dest)
            break;
        for (Edge *e: aux->getAdj()) {
            Node *next = e->getDest();
            if (std::find(closedAux.begin(), closedAux.end(), next) !=
                closedAux.end()) {
                break;
            }
            next->setEuclidianDist(next->calculateDist(dest));
            next->setCost(e->getCost() + next->getEuclidianDist());

            if (std::find(openAux.begin(), openAux.end(), next) == openAux.end()) {
                next->setPath(aux);
                if (next->getCost() > aux->getCost())
                    break;
            }
            openQueue.push(next);
            openAux.push_back(next);
        }
    }
    return getPath(graph, orig);
}

std::vector<Node *> getPath(Graph graph, Node *n) {
    std::vector<Node *> res;
    Node *aux = graph.findNode(n);

    while (aux != nullptr) {
        res.insert(res.begin(), aux);
        aux = aux->getPath();
    }
    return res;
}
