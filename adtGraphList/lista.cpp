#include "Lista.h"
#include <iostream>

Lista::Lista()
{
    header = nullptr;
    // header->next = nullptr;
}
Lista::~Lista()
{
    if (header != nullptr)
    {
        cell *komorka = header;
        cell *nextCell;
        while (komorka != nullptr)
        {
            nextCell = komorka->next;
            delete komorka;
            komorka = nextCell;
        }
        header = 0;
    }
}
void Lista::Insert(int x, cell *p = nullptr, int node = 0)
{
    if (header != nullptr)
    {
        if (p == nullptr)
        {
            cell *komorka = new cell();
            komorka->element = x;
            komorka->next = header;
            header = komorka;
            if (node != 0)
                komorka->node = node;
            size++;
        }
        else
        {
            cell *komorka = new cell();
            komorka->element = x;
            komorka->next = p->next;
            p->next = komorka;
            if (node != 0)
                komorka->node = node;
            size++;
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
            if (node != 0)
                komorka->node = node;
            size++;
        }
        else
        {
            cell *komorka = new cell();
            komorka->element = x;
            header = komorka;
            header->next = nullptr;
            if (node != 0)
                komorka->node = node;
            size++;
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
// void Lista::DeleteNode(int x)
// {
//     if (LocateNode(x) != nullptr)
//     {
//         cell *temp;
//         temp = header;
//         if (LocateNode(x) != header)
//         {
//             cell *prev;
//             while (temp->next != LocateNode(x)->next && temp->next != nullptr)
//             {
//                 prev = temp;
//                 temp = temp->next;
//             }
//             prev->next = temp->next;
//         }
//         else
//         {
//             header = temp->next;
//             header->next = temp->next->next;
//         }
//         delete LocateNode(x);
//     }
// }

int Lista::Retrieve(cell *p)
{
    if (p != nullptr)
        return p->element;
    else
        return 0;
}

cell *Lista::Locate(int x) const
{
    cell *temp;
    temp = header;
    if (temp != nullptr)
    {
        while (temp->element != x)
        {
            if (temp->next == nullptr)
                return nullptr;
            temp = temp->next;
        }
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
    if (temp != nullptr)
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
    }
    return temp;
}
cell *Lista::Locate(int x, int y)
{
    cell *temp;
    temp = header;
    if (temp != nullptr)
    {
        while (temp->element != x && temp->node != y)
        {
            if (temp->next == nullptr)
                return nullptr;
            temp = temp->next;
        }
    }
    return temp;
}
cell *Lista::LocateNode(int y)
{
    cell *temp;
    temp = header;
    if (temp != nullptr)
    {
        while (temp->node != y)
        {
            if (temp->next == nullptr)
                return nullptr;
            temp = temp->next;
        }
    }
    return temp;
}
void Lista::print()
{
    cell *temp;
    temp = header;
    while (temp != nullptr)
    {
        std::cout << temp->node << "|" << temp->element;
        if (temp->next != nullptr)
            std::cout << " -> ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Lista &Lista::operator=(const Lista &source)
{
    if (this != &source)
    {
        if (header != nullptr)
        {
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

        if (source.header != nullptr)
        {
            cell *prev = source.header;
            cell *komorka = source.header;
            while (komorka != nullptr)
            {
                this->Insert(komorka->element, Locate(prev->element), 0);
                this->print();
                prev = komorka;
                komorka = komorka->next;
            }
        }
    }
    return *this;
}
Lista &Lista::operator=(Lista &&source)
{
    if (this != &source)
    {
        if (header != nullptr)
        {
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

        if (source.header != nullptr)
        {
            cell *komorka = source.header;
            while (komorka->next != nullptr)
            {
                Insert(komorka->element);
                komorka = komorka->next;
            }
        }

        if (source.header != nullptr)
        {
            cell *komorka = source.header;
            cell *nextCell;
            while (komorka->next != nullptr)
            {
                nextCell = komorka->next;
                delete komorka;
                komorka = nextCell;
            }
            source.header = 0;
        }
    }
    return *this;
}

void Lista::clear()
{
    if (header != nullptr)
    {
        cell *komorka = header;
        cell *nextCell;
        while (komorka != nullptr)
        {
            nextCell = komorka->next;
            delete komorka;
            komorka = nextCell;
        }
        header = 0;
    }
}