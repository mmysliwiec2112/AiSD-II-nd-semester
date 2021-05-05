#include "setSimpleEven.h"
#include <iostream>

setSimpleEven::setSimpleEven(int n, int m) : beggining(m > n ? n : m), end(m > n ? m : n)
{
    if (beggining % 2 == 1)
    {
        beggining++;
    }
    if (end % 2 == 1)
    {
        end--;
    }
    set = new bool[(end - beggining) / 2 + 1];
    for (int i = beggining; i < end; i = i + 2)
    {
        set[i / 2] = false;
    }
    size = (end - beggining) / 2 + 1;
}

setSimpleEven::setSimpleEven(int n, int m, int tab[]) : beggining(m > n ? n : m), end(m > n ? m : n)
{
    if (beggining % 2 == 1)
    {
        beggining++;
    }
    if (end % 2 == 1)
    {
        end--;
    }
    set = new bool[(end - beggining) / 2 + 1];
    size = (end - beggining) / 2 + 1;
    int j = 0;
    for (int i = 0; i <= size; i ++)
    {
        if (tab[j] == beggining + (i * 2))
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
void setSimpleEven::print()
{
    std::cout << "[ ";
    for (int i = 0; i <= size; i ++)
    {
        if (set[i] == true)
            std::cout << beggining + (i * 2) << " ";
    }
    std::cout << "]" << std::endl;
}

void setSimpleEven::add(int element)
{
    if (element >= beggining && element <= end)
    {
        set[(element - beggining) / 2] = true;
    }
    else
        std::cout << "Invalid number, please enter an integer between " << beggining << " and " << end << std::endl;
}
void setSimpleEven::remove(int element)
{
    if (element >= beggining && element <= end)
    {
        set[(element - beggining) / 2] = false;
    }
    else
        std::cout << "Invalid number, please enter an integer between " << beggining << " and " << end << std::endl;
}
bool setSimpleEven::check(int element)
{
    if (element >= beggining && element <= end)
    {
        return set[(element - beggining) / 2];
    }
    else
        return false;
}

setSimpleEven setSimpleEven::setUnion(setSimpleEven set)
{
    setSimpleEven temp(this->beggining > set.beggining ? this->beggining : set.beggining, this->end < set.end ? this->end : set.end);
    for (int i = 0; i < temp.size; i++)
    {
        temp.set[i] = (this->set[i] || set.set[i]) ? true : false;
    }
    return temp;
}

setSimpleEven setSimpleEven::setIntersection(setSimpleEven set)
{
    setSimpleEven temp(this->beggining > set.beggining ? this->beggining : set.beggining, this->end < set.end ? this->end : set.end);
    for (int i = 0; i < temp.size; i++)
    {
        temp.set[i] = (this->set[i] && set.set[i]) ? true : false;
    }
    return temp;
}

setSimpleEven setSimpleEven::setDifference(setSimpleEven set)
{
    setSimpleEven temp(this->beggining > set.beggining ? this->beggining : set.beggining, this->end < set.end ? this->end : set.end);
    for (int i = 0; i < temp.size; i++)
    {
        temp.set[i] = (this->set[i] && !set.set[i]) ? true : false;
    }
    return temp;
}