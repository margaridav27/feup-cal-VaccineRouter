/*
 * MutablePriorityQueue.h
 * A simple implementation of mutable priority queues, required by Dijkstra algorithm.
 *
 * Created on: 17/03/2018
 *      Author: João Pascoal Faria
 */

#ifndef SRC_MUTABLEPRIORITYQUEUE_H_
#define SRC_MUTABLEPRIORITYQUEUE_H_

#include <vector>

/**
 * class T must have: (i) accessible field int queueIndex; (ii) operator< defined.
 */
#include "../graph/node/Node.h"

class MutablePriorityQueue {
private:
    std::vector<Node *> H;
    void heapifyUp(unsigned i);
    void heapifyDown(unsigned i);
    inline void set(unsigned i, Node *x);
public:
    MutablePriorityQueue();
    void insert(Node *x);
    Node *extractMin();
    void decreaseKey(Node *x);
    bool empty();
};

// Index calculations
#define parent(i) ((i) / 2)
#define leftChild(i) ((i) * 2)


#endif /* SRC_MUTABLEPRIORITYQUEUE_H_ */
