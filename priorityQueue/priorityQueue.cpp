#include "priorityQueue.h"
#include "setSimple.h"
#include <iostream>

priorityQueue::priorityQueue(){}
priorityQueue::priorityQueue(int tab[], int size)
{
    setForQueue = new setSimple(tab, size);
}
priorityQueue::~priorityQueue()
{
}
priorityQueue::priorityQueue(const priorityQueue &source)
{
    if (this != &source)
    {
        setForQueue = new setSimple(*source.setForQueue);
    }
}
priorityQueue::priorityQueue(priorityQueue &&source)
{
    if (this != &source)
    {
        setForQueue = new setSimple(*source.setForQueue);
        for(int i = 0; i < 1000; i++){
            setForQueue->remove(i);
        }
        source.setForQueue = nullptr;
    }
}
void priorityQueue::add(int element){
    setForQueue->add(element);
}
int priorityQueue::pop(){
    for(int i = 0; i < 1000; i++){
        if(setForQueue->check(i) == true){
            setForQueue->remove(i);
            return i;
        }
    }
    return -1;
}
void priorityQueue::print(){
    setForQueue->print();
}