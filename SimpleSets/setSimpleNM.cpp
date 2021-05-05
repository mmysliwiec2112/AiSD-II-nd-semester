#include "setSimpleNM.h"
#include <iostream>
#include <fstream>

setSimpleNM::setSimpleNM(int n, int m) : beggining(m > n ? n : m), end(m > n ? m : n), set(new bool[m > n ? m - n : n - m])
{
    if (n < m)
    {
        for (int i = n; i < m; i++)
        {
            set[i] = false;
        }
    }
    else if (m != n)
    {
        for (int i = m; i < n; i++)
        {
            set[i] = false;
        }
    }
}
setSimpleNM::setSimpleNM(int n, int m, int tab[]) : beggining(m > n ? n : m), end(m > n ? m : n), set(new bool[m > n ? m - n : n - m])
{
    if (n < m)
    {
        int j = 0;
        for (int i = n; i < m; i++)
        {
            if (tab[j] == i)
            {
                set[i] = true;
                j++;
            }
            else
                set[i] = false;
        }
    }
    else if (m != n)
    {
        int j = 0;
        for (int i = m; i < n; i++)
        {
            if (tab[j] == i)
            {
                set[i] = true;
                j++;
            }
            else
                set[i] = false;
        }
    }
}
// setSimpleNM::~setSimpleNM()
// {
//     delete[] set;
// }
void setSimpleNM::print()
{
    std::cout << "[ ";
    for (int i = beggining; i < end; i++)
    {
        if (set[i] == true)
            std::cout << i << " ";
    }
    std::cout << "]" << std::endl;
}

void setSimpleNM::add(int element)
{
    if (element >= beggining && element <= end)
    {
        set[element] = true;
    }
    else
        std::cout << "Invalid number, please enter an integer between " << beggining << " and " << end << std::endl;
}
void setSimpleNM::remove(int element)
{
    if (element >= beggining && element <= end)
    {
        set[element] = false;
    }
    else
        std::cout << "Invalid number, please enter an integer between " << beggining << " and " << end << std::endl;
}
bool setSimpleNM::check(int element)
{
    if (element >= beggining && element <= end)
    {
        return set[element];
    }
    else
        return false;
}

setSimpleNM setSimpleNM::setUnion(setSimpleNM set)
{
    setSimpleNM temp(this->beggining > set.beggining ? this->beggining : set.beggining, this->end < set.end ? this->end : set.end);
    for (int i = temp.beggining; i < temp.end; i++)
    {
        temp.set[i] = (this->set[i] || set.set[i]) ? true : false;
    }
    return temp;
}

setSimpleNM setSimpleNM::setIntersection(setSimpleNM set)
{
    setSimpleNM temp(this->beggining > set.beggining ? this->beggining : set.beggining, this->end < set.end ? this->end : set.end);
    for (int i = temp.beggining; i < temp.end; i++)
    {
        temp.set[i] = (this->set[i] && set.set[i]) ? true : false;
    }
    return temp;
}

setSimpleNM setSimpleNM::setDifference(setSimpleNM set)
{
    setSimpleNM temp(this->beggining > set.beggining ? this->beggining : set.beggining, this->end < set.end ? this->end : set.end);
    for (int i = temp.beggining; i < temp.end; i++)
    {
        temp.set[i] = (this->set[i] && !set.set[i]) ? true : false;
    }
    return temp;
}
