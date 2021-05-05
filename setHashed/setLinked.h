#pragma once
#include "Lista.h"

class setLinked{
    Lista listSet;
    public:
    setLinked() = default;
    ~setLinked();
    setLinked(const setLinked& source) = default;
    setLinked(setLinked&& source) = default;

    //operator overloads
    setLinked& operator=(const setLinked& source);
    // setLinked& operator=(setLinked&& source);

    // for an element x and a set
    void add(int x);
    void remove(int x);
    bool check(int x);
    void print();

    // for two sets
    setLinked setUnion(setLinked& set);
    setLinked setIntersection(setLinked& set);
    setLinked setDifference(setLinked& set);
    bool isEqual(setLinked& set);
};