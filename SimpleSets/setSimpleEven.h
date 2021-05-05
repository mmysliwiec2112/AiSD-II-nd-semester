#pragma once

class setSimpleEven{

    bool *set;
    int beggining;
    int end;
    int size;
    public:
    setSimpleEven(int n, int m);
    setSimpleEven(int n, int m, int tab[]);
    setSimpleEven(const setSimpleEven& source) = default;
    setSimpleEven(setSimpleEven&& source) = default;
    ~setSimpleEven() = default;

    void print();
    void add(int element);
    void remove(int element);
    bool check(int element);

    setSimpleEven setUnion(setSimpleEven set);
    setSimpleEven setIntersection(setSimpleEven set);
    setSimpleEven setDifference(setSimpleEven set);
};