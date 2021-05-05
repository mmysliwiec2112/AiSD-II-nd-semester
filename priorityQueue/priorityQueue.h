#pragma once
#include "setSimple.h"
class priorityQueue {
    setSimple* setForQueue;
    //returns the priority of a given element
    int p(int element){
        return element;
    }

    public:
    priorityQueue();
    priorityQueue(int size);
    priorityQueue(int tab[], int size);
    ~priorityQueue();
    priorityQueue(const priorityQueue& source);
    priorityQueue(priorityQueue&& source);

    //adds an element with a priority equal to the value of this element
    void add(int element);
    //returns an element with the lowest priority
    int pop();
    void print();
    

};