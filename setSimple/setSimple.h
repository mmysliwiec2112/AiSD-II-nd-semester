#pragma once

class setSimple{   
    //domyslnie omega to liczby naturalne od 1 do 1000, nie potrzeba implementacji wprost - wystarczy sprawdzac to w petli
    bool set[1000];

    public:
    setSimple() = default;
    setSimple(int tab[]);
    ~setSimple() = default;
    setSimple(const setSimple& source) = default;
    setSimple(setSimple&& source) = default;

    //operator overloads
    setSimple operator=(const setSimple& source);
    setSimple operator=(setSimple&& source);

    // for an element x and a set
    void add(int element);
    void remove(int element);
    bool check(int element);
    void print();

    // for two sets
    setSimple setUnion(setSimple set);
    setSimple setIntersection(setSimple set);
    setSimple setDifference(setSimple set);
};
