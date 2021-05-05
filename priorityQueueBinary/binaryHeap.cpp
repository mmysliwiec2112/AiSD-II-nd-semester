#include "binaryHeap.h"
#include <iostream>
#include <math.h>

binaryHeap::binaryHeap() : size(0), maxSize(10), heap(new int[10]) {}
binaryHeap::binaryHeap(int tab[], int size_) : size(size_), maxSize(size_ + 10), heap(new int[size_ + 10])
{
    for (int i = 0; i < size_; i++)
    {
        heap[i] = tab[i];
    }
    sort();
}
binaryHeap::binaryHeap(const binaryHeap &source)
{
    if (this != &source)
    {
        delete[] heap;
        this->size = 0;
        this->maxSize = 0;
        size = source.size;
        maxSize = source.maxSize;
        heap = new int[source.maxSize];
        for (int i = 0; i < source.size; i++)
        {
            heap[i] = source.heap[i];
        }
    }
}
binaryHeap::binaryHeap(binaryHeap &&source)
{
    if (this != &source)
    {
        delete[] heap;
        this->size = 0;
        this->maxSize = 0;
        size = source.size;
        maxSize = source.maxSize;
        heap = new int[source.maxSize];
        for (int i = 0; i < source.size; i++)
        {
            heap[i] = source.heap[i];
        }
        source.size = 0;
        source.maxSize = 0;
        delete[] source.heap;
        heap = nullptr;
    }
}
binaryHeap::~binaryHeap()
{
    size = 0;
    maxSize = 0;
    delete[] heap;
}
binaryHeap &binaryHeap::operator=(const binaryHeap &source)
{
    if (this != &source)
    {
        delete[] this->heap;
        int size = source.size;
        int maxSize = source.maxSize;
        heap = new int[maxSize];
        for (int i = 0; i < source.size; i++)
        {
            heap[i] = source.heap[i];
        }
    }
    return *this;
}
binaryHeap &binaryHeap::operator=(binaryHeap &&source)
{
    if (this != &source)
    {
        delete[] this->heap;
        int size = source.size;
        int maxSize = source.maxSize;
        heap = new int[maxSize];
        for (int i = 0; i < source.size; i++)
        {
            heap[i] = source.heap[i];
        }
        source.size = 0;
        source.maxSize = 0;
        delete[] source.heap;
        heap = nullptr;
    }
    return *this;
}
int binaryHeap::parentId(int id)
{
    return floor((id - 1) / 2);
}
int binaryHeap::leftSonId(int id)
{
    return 2 * id + 1;
}
int binaryHeap::rightSonId(int id)
{
    return 2 * id + 2;
}
void binaryHeap::add(int element)
{
    if (size >= maxSize - 1)
    {
        int *tempPointer = new int[maxSize + 10];
        for (int i = 0; i < size; i++)
        {
            tempPointer[i] = heap[i];
        }
        delete[] heap;
        heap = tempPointer;
        tempPointer = nullptr;
    }
    heap[size] = element;
    size++;
    sort();
}
int binaryHeap::elementId(int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element == heap[i])
            return i;
    }
    return -1;
}
int binaryHeap::remove(int id)
{
    if (id >= 0 && id < size)
    {
        int returningValue = heap[id];
        for (int i = id + 1; i < size; i++)
        {
            heap[i - 1] = heap[i];
        }
        size = size - 1;
        sort();
        return returningValue;
    }
    else
        return -1;
}
void binaryHeap::sort()
{
    heapify();
    int i = size - 1;
    while (i >= 0)
    {
        std::swap(heap[i], heap[0]);
        i--;
        siftDown(0, i);
    }
}
void binaryHeap::heapify()
{
    for (int i = size - 1; i >= 0; i--)
    {
        siftDown(i, size - 1);
    }
}
int binaryHeap::siftDown(int start, int end)
{
    int root = start;
    int child, swap;
    while (leftSonId(root) <= end)
    {
        child = leftSonId(root);
        swap = root;

        if (heap[swap] < heap[child])
            swap = child;
        if (child + 1 <= end && heap[swap] < heap[child + 1])
            swap = child + 1;
        if (swap == root)
        {
            return 1;
        }
        else
        {
            std::swap(heap[root], heap[swap]);
            root = swap;
        }
    }
    return -1;
}
void binaryHeap::print()
{
    for (int i = 0; i < size; ++i)
        std::cout << heap[i] << " ";
    std::cout << std::endl;
}