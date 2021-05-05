#include "priorityQueueBinary.h"
#include <iostream>

priorityQueueBinary::priorityQueueBinary()
{

}
priorityQueueBinary::~priorityQueueBinary()
{
    //tylko wywołanie destruktora kopca
}
priorityQueueBinary::priorityQueueBinary(int tab[], int size) : heapQueue(tab, size)
{
}
priorityQueueBinary::priorityQueueBinary(const priorityQueueBinary &source)
{
    if(this != &source){
        this->heapQueue = source.heapQueue;
    }
}
priorityQueueBinary::priorityQueueBinary(priorityQueueBinary &&source)
{
    if(this != &source){
        this->heapQueue = source.heapQueue;
        delete &source;
    }
}
void priorityQueueBinary::add(int element){
    heapQueue.add(element);
}
int priorityQueueBinary::pop(){
    return heapQueue.remove(0);
}
void priorityQueueBinary::print(){
    heapQueue.print();
}
