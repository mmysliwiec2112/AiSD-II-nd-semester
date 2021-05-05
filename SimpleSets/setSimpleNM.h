#pragma once

class setSimpleNM{

    bool *set;
    int beggining;
    int end;
    public:
    setSimpleNM(int n, int m);
    setSimpleNM(int n, int m, int tab[]);
    setSimpleNM(const setSimpleNM& source) = default;
    setSimpleNM(setSimpleNM&& source) = default;
    ~setSimpleNM() = default;

    void print();
    void add(int element);
    void remove(int element);
    bool check(int element);

    setSimpleNM setUnion(setSimpleNM set);
    setSimpleNM setIntersection(setSimpleNM set);
    setSimpleNM setDifference(setSimpleNM set);
};