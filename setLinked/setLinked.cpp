#include "setLinked.h"
#include "Lista.h"
#include <iostream>
setLinked::~setLinked()
{
    std::cout<<"obiekt usuwany"<<std::endl;
}

void setLinked::add(int x)
{
    if (listSet.First() == nullptr)
    {
        listSet.Insert(x, listSet.First());
    }
    else if (listSet.Locate(x) == nullptr)
    {
        cell *temp = listSet.First();
        while (temp != nullptr && temp->element < x)
        {
            if (temp != nullptr)
                temp = listSet.Next(temp);
            // std::cout<<"jestem w petli while"<<std::endl;
        }
        if (temp == nullptr)
        {
            // std::cout<<"dodaje element za ostatni element listy"<<std::endl;
            listSet.Insert(x, listSet.Last());
        }
        else if (temp == listSet.First())
        {
            // std::cout<<"dodaje element jako nowy nagłówek"<<std::endl;
            listSet.Insert(x, nullptr);
        }
        else
        {
            // std::cout<<"dodaje element jako jeden z wewnętrznych węzłów"<<std::endl;
            listSet.Insert(x, listSet.Previous(temp));
        }
    }
}
void setLinked::remove(int x)
{
    listSet.Delete(listSet.Locate(x));
}
bool setLinked::check(int x)
{
    if (listSet.Locate(x) == nullptr)
        return false;
    else
        return true;
}
void setLinked::print()
{
    listSet.print();
}
setLinked setLinked::setUnion(setLinked &set)
{
    setLinked tempUnion;
    cell *thisTemp = this->listSet.First();
    cell *setTemp = set.listSet.First();
    while (thisTemp != nullptr)
    {
        tempUnion.add(thisTemp->element);
        thisTemp = this->listSet.Next(thisTemp);
    }
    // this->print();
    // tempUnion.print();
    // set.print();
    // std::cout<<"Element set "<< setTemp->element<<std::endl;
    while (setTemp != nullptr)
    {
        // std::cout<<"Element this "<< thisTemp->element<<std::endl;
        if (tempUnion.check(setTemp->element))
        {
            // std::cout<<"Element jest obecny: "<< setTemp->element<<std::endl;
            setTemp = set.listSet.Next(setTemp);
        }
        else
        {
            // std::cout<<"wstawiam element "<< setTemp->element<<std::endl;
            tempUnion.add(setTemp->element);
            // tempUnion.print();
            setTemp = set.listSet.Next(setTemp);
        }
    }
    // tempUnion.print();
    return tempUnion;
}
setLinked setLinked::setIntersection(setLinked &set)
{
    setLinked tempIntersection;
    cell *thisTemp = this->listSet.First();
    cell *setTemp = set.listSet.First();
    while (setTemp != nullptr)
    {
        if (this->check(setTemp->element))
        {
            tempIntersection.add(setTemp->element);
            setTemp = set.listSet.Next(setTemp);
        }
        else
        {
            setTemp = set.listSet.Next(setTemp);
        }
    }
    thisTemp = nullptr;
    setTemp = nullptr;
    return tempIntersection;
}
setLinked setLinked::setDifference(setLinked &set)
{
    setLinked tempDifference;
    cell *thisTemp = this->listSet.First();
    cell *setTemp = set.listSet.First();
    while (thisTemp != nullptr)
    {
        tempDifference.add(thisTemp->element);
        thisTemp = this->listSet.Next(thisTemp);
    }
    while (setTemp != nullptr)
    {
        if (tempDifference.check(setTemp->element))
        {
            tempDifference.remove(setTemp->element);
        }
        else
        {
            setTemp = set.listSet.Next(setTemp);
        }
    }
    return tempDifference;
}

setLinked &setLinked::operator=(const setLinked &source)
{
    if (&source != this)
    {
        cell* temp;
        if(this->listSet.header != nullptr){
        temp = this->listSet.First();
        cell* next;
        while(temp->next != nullptr){
            next = temp->next;
            delete temp;
            temp = next;
        }
        listSet.header = nullptr;
        }

        temp = source.listSet.First();
        while(temp != nullptr){
            this->add(temp->element);
            temp = temp->next;
        }
    }
    return *this;
}
