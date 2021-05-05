#include "Lista.h"
#include <iostream>

Lista::Lista()
{
    header = nullptr;
    // header->next = nullptr;
}
Lista::~Lista()
{
    if(header != nullptr){
    cell *komorka = header;
    cell *nextCell;
    while (komorka->next != nullptr)
    {
        nextCell = komorka->next;
        delete komorka;
        komorka = nextCell;
    }
    header = 0;
    }
}
void Lista::Insert(int x, cell *p = nullptr)
{
    if (header != nullptr)
    {
        if (p == nullptr)
        {
            cell *komorka = new cell();
            komorka->element = x;
            komorka->next = header;
            header = komorka;
        }   
        else
        {
            cell *komorka = new cell();
            komorka->element = x;
            komorka->next = p->next;
            p->next = komorka;
        }
    }
    else
    {
        if (p == nullptr)
        {
            cell *komorka = new cell();
            komorka->element = x;
            komorka->next = nullptr;
            header = komorka;
        }
        else
        {
            cell *komorka = new cell();
            komorka->element = x;
            header = komorka;
            header->next = nullptr;
        }
    }
}

void Lista::Delete(cell *p)
{
    if (p != nullptr)
    {
        cell *temp;

        temp = header;
        if (p != header)
        {
            cell *prev;
            while (temp->next != p->next && temp->next != nullptr)
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
        }
        else
        {
            header = temp->next;
            header->next = temp->next->next;
        }
        delete p;
    }
}

int Lista::Retrieve(cell *p)
{
    if (p != nullptr)
        return p->element;
    else
        return 0;
}

cell *Lista::Locate(int x)
{
    cell *temp;
    temp = header;
    while (temp->element != x)
    {
        if (temp->next == nullptr)
            return nullptr;
        temp = temp->next;
    }
    return temp;
}

cell *Lista::First() const
{
    return header;
}

cell *Lista::Next(cell *p) const
{
    if (p != nullptr || p->next != nullptr)
    {
        return p->next;
    }
    else
        return nullptr;
}

cell *Lista::Previous(cell *p)
{
    if (p != nullptr)
    {
        cell *temp;
        cell *prev;
        temp = header;
        while (temp->next != p->next && temp->next != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }
        return prev;
    }
    return nullptr;
}

cell *Lista::Last() const
{
    cell *temp;
    temp = header;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    return temp;
}
void Lista::print()
{
    cell *temp;
    temp = header;
    while (temp != nullptr)
    {
        std::cout << temp->element << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}