#pragma once

class binaryHeap
{
    int size;
    int maxSize;
    int *heap;
    public:

    binaryHeap();
    binaryHeap(int tab[], int size_);
    ~binaryHeap();
    binaryHeap(const binaryHeap& source);
    binaryHeap(binaryHeap&& source);

    binaryHeap& operator=(const binaryHeap& source);
    binaryHeap& operator=(binaryHeap&& source);

    int parentId(int id);
    int leftSonId(int id);
    int rightSonId(int id);
    void add(int element);
    int remove (int id);
    int elementId(int element);
    void sort();
    void print();
    int siftDown(int start, int end);
    void heapify();
};