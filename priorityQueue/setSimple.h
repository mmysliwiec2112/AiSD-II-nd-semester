#pragma once

class setSimple{   
    //domyslnie omega to liczby naturalne od 1 do 1000, nie potrzeba implementacji wprost - wystarczy sprawdzac to w petli
    bool* set;

    public:
    setSimple();
    setSimple(int tab[], int size);
    ~setSimple();
    setSimple(const setSimple& source);
    setSimple(setSimple&& source);

    //operator overloads
    setSimple operator=(const setSimple& source);
    setSimple operator=(setSimple&& source);

    // for an element x and a set
    void add(int element);
    void remove(int element);
    bool check(int element);
    void print();
    bool* setPointer(){
        return set;
    }

    // for two sets
    setSimple setUnion(setSimple set);
    setSimple setIntersection(setSimple set);
    setSimple setDifference(setSimple set);
};
