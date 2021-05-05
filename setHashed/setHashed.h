#pragma once
#include "setLinked.h"

class setHashed{
    setLinked** hashBuckets;
    int size;

    //hashing function that puts given element into one of five buckets
    int hashFun(int element);

    public:
    setHashed() = default;
    setHashed(int size);
    ~setHashed();
    setHashed(const setHashed& source);
    setHashed(setHashed&& source) = default;

    //set operations

    setHashed setUnion(setHashed& source);
    setHashed setIntersection(setHashed& source);
    setHashed setDifference(setHashed& source);
    bool isEqual(setHashed& source);

    //element operations

    void add(int element);
    void remove(int element);
    bool check(int element);
    void print();

};