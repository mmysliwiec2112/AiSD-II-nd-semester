#pragma once
#include "binaryHeap.h"

class priorityQueueBinary{
    binaryHeap heapQueue;

    public:
    priorityQueueBinary();
    ~priorityQueueBinary();
    priorityQueueBinary(int tab[], int size);
    priorityQueueBinary(const priorityQueueBinary& source);
    priorityQueueBinary(priorityQueueBinary&& source);

    void add(int element);
    int pop();
    void print();
};