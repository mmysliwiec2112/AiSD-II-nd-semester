#include "setSimple.h"
#include <iostream>
#include <fstream>
#include <chrono>
setSimple::setSimple()
{
    set = new bool[1000];
    for (int i = 0; i < 1000; i++)
        {
            set[i] = false;
        }
}
setSimple::setSimple(int tab[], int size)
{
    if (tab != nullptr)
    {
        set = new bool[1000];
        int j = 0;
        for (int i = 0; i < 1000; i++)
        {
            if (j < size && tab[j] == i)
            {
                set[i] = true;
                j++;
            }
            else
            {
                set[i] = false;
            }
        }
    }
}
setSimple::setSimple(const setSimple &source)
{
    if (this != &source)
    {
        delete[] set;
        set = new bool[1000];
        for (int i = 0; i < 1000; i++)
        {
            set[i] = source.set[i];
        }
    }
}
setSimple::setSimple(setSimple &&source)
{
    if (this != &source)
    {
        delete[] set;
        set = new bool[1000];
        for (int i = 0; i < 1000; i++)
        {
            set[i] = source.set[i];
        }
        for (int i = 0; i < 1000; i++)
        {
            source.set[i] = 0;
        }
    }
}
setSimple::~setSimple()
{
    delete[] set;
}
setSimple setSimple::operator=(const setSimple &source)
{
    setSimple temp;
    for (int i = 0; i < 1000; i++)
    {
        temp.set[i] = source.set[i];
    }
    return temp;
}
setSimple setSimple::operator=(setSimple &&source)
{
    setSimple temp;
    for (int i = 0; i < 1000; i++)
    {
        temp.set[i] = source.set[i];
        source.set[i] = false;
    }
    return temp;
}

void setSimple::add(int element)
{
    if (element >= 0 && element <= 999)
    {
        set[element] = true;
    }
    else
        std::cout << "Invalid number, please enter an integer between 0 and 999" << std::endl;
}
void setSimple::remove(int element)
{
    if (element >= 0 && element <= 999)
    {
        set[element] = false;
    }
    else
        std::cout << "Invalid number, please enter an integer between 0 and 999" << std::endl;
}
bool setSimple::check(int element)
{
    if (element >= 0 && element <= 999)
    {
        if (set[element] == true)
            return true;
        else
            return false;
    }
    else
        return false;
}
void setSimple::print()
{
    std::cout << "[";
    for (int i = 0; i < 1000; i++)
    {
        if (set[i] == true)
            std::cout << " " << i;
    }
    std::cout << " ]" << std::endl;
}

setSimple setSimple::setUnion(setSimple set)
{
    setSimple temp;
    for (int i = 0; i < 1000; i++)
    {
        temp.set[i] = (this->set[i] || set.set[i]) ? true : false;
    }
    return temp;
}
setSimple setSimple::setIntersection(setSimple set)
{
    setSimple temp;
    for (int i = 0; i < 1000; i++)
    {
        temp.set[i] = (this->set[i] && set.set[i]) ? true : false;
    }
    return temp;
}
setSimple setSimple::setDifference(setSimple set)
{
    setSimple temp;
    for (int i = 0; i < 1000; i++)
    {
        temp.set[i] = (this->set[i] && !set.set[i]) ? true : false;
    }
    return temp;
}