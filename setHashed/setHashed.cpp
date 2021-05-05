#include "setHashed.h"
#include <iostream>
#include "setLinked.h"

setHashed::setHashed(int element) : size(element)
{
    hashBuckets = new setLinked *[size];
    for (int i = 0; i < size; i++)
    {
        hashBuckets[i] = new setLinked;
    }
}

setHashed::~setHashed()
{
}
setHashed::setHashed(const setHashed &source) : size(source.size)
{
    if (this != &source)
    {
        cell* temp;
        hashBuckets = new setLinked *[size];
        for (int i = 0; i < size; i++)
        {
            hashBuckets[i] = new setLinked;
            hashBuckets[i] = source.hashBuckets[i];
        }
    }
}
int setHashed::hashFun(int element)
{
    return element % size;
}

void setHashed::print()
{
    for (int i = 0; i < size; i++)
    {
        hashBuckets[i]->print();
    }
}

void setHashed::add(int element)
{
    int id = hashFun(element);
    hashBuckets[id]->add(element);
}

void setHashed::remove(int element)
{
    int id = hashFun(element);
    hashBuckets[id]->remove(element);
}

bool setHashed::check(int element)
{
    int id = hashFun(element);
    return hashBuckets[id]->check(element);
}

setHashed setHashed::setUnion(setHashed &source)
{
    setHashed tempUnion(size);
    for (int i = 0; i < size; i++)
    {
        *(tempUnion.hashBuckets[i]) = hashBuckets[i]->setUnion(*source.hashBuckets[i]);
    }
    // tempUnion.print();
    return tempUnion;
}

setHashed setHashed::setIntersection(setHashed &source)
{
    setHashed tempIntersection(size);
    for (int i = 0; i < size; i++)
    {
        *(tempIntersection.hashBuckets[i]) = hashBuckets[i]->setIntersection(*source.hashBuckets[i]);
    }
    return tempIntersection;
}

setHashed setHashed::setDifference(setHashed &source)
{
    setHashed tempDifference(size);
    for (int i = 0; i < size; i++)
    {
        *(tempDifference.hashBuckets[i]) = hashBuckets[i]->setDifference(*source.hashBuckets[i]);
    }
    return tempDifference;
}

bool setHashed::isEqual(setHashed &source)
{
    int value = 0;
    for (int i = 0; i < size; i++)
    {
        value += hashBuckets[i]->isEqual(*source.hashBuckets[i]);
    }
    return value == size ? true : false;
}