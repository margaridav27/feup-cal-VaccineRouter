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

template<class T>
class MutablePriorityQueue {
private:
    std::vector<T *> H;
    void heapifyUp(unsigned i);
    void heapifyDown(unsigned i);
    inline void set(unsigned i, T *x);
public:
    MutablePriorityQueue();
    void insert(T *x);
    T *extractMin();
    void decreaseKey(T *x);
    bool empty();
};

// Index calculations
#define parent(i) ((i) / 2)
#define leftChild(i) ((i) * 2)


#endif /* SRC_MUTABLEPRIORITYQUEUE_H_ */
