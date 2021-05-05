#pragma once

struct Word
{
    int wordArray[50];
    Word *next;
};

class setDictionary
{
public:
    Word *head;
    setDictionary()
    {
        head = nullptr;
    };
    ~setDictionary();

    void add(int tab[]);
    void remove(int tab[]);
    bool check(int tab[]);
    //compares two words, returns 1 if the first one is greater than the second one, returns -1 if the second one is greater than the first one, returns 0 if words are equal
    int compare(int tab1[], int tab2[]);
    void print();
};