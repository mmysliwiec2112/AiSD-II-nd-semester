#include "setDictionary.h"
#include <iostream>

setDictionary::~setDictionary()
{
    Word *word = head;
    while (word != nullptr)
    {
        Word *next = word->next;
        delete word;
        word = next;
    }
    head = nullptr;
}

void setDictionary::add(int tab[])
{
    if (tab != nullptr)
    {
        if (head == nullptr)
        {
            // std::cout << "header doesn't exist" << std::endl;
            Word *word = new Word();
            for (int i = 0; i < 50; i++)
            {
                word->wordArray[i] = tab[i];
            }
            word->next = nullptr;
            head = word;
        }
        else if (head->next != nullptr)
        {
            // std::cout << "header exists and header->next also exists" << std::endl;
            Word *word = new Word();
            for (int i = 0; i < 50; i++)
            {
                word->wordArray[i] = tab[i];
            }
            word->next = nullptr;
            Word *nextPointer = head;
            Word *prevPointer = head;
            int result;
            while (nextPointer != nullptr)
            {
                result = compare(word->wordArray, nextPointer->wordArray);
                if (result == 1)
                {
                    // std::cout << "word which is added is greater than the current one" << std::endl;
                    prevPointer = nextPointer;
                    nextPointer = nextPointer->next;
                }
                else if (result == -1)
                {
                    // std::cout << "adding new word" << std::endl;
                    word->next = nextPointer;
                    prevPointer->next = word;
                }
                if (nextPointer == nullptr && result != 0)
                {
                    // std::cout << "word which is added is greater than all of words in dictionary, so it becomes the last word" << std::endl;
                    word->next = nullptr;
                    prevPointer->next = word;
                }
            }
        }
        else
        {
            // std::cout << "header exists, but header->next doesn't" << std::endl;
            Word *word = new Word();
            for (int i = 0; i < 50; i++)
            {
                word->wordArray[i] = tab[i];
            }
            word->next = nullptr;
            int result = compare(word->wordArray, head->wordArray);
            if (result == 1)
            {
                head->next = word;
            }
            else if (result == -1)
            {
                word->next = head;
                head = word;
            }
        }
    }
    // else
    // std::cout << "tab doesn't exist" << std::endl;
}
void setDictionary::remove(int tab[])
{
    Word *nextPointer = head;
    Word *prevPointer = head;
    int result = 2;
    while (nextPointer != nullptr)
    {
        result = compare(tab, nextPointer->wordArray);
        if (result == 0)
        {
            prevPointer->next = nextPointer->next;
            for (int i = 0; i < 50; i++)
            {
                nextPointer->wordArray[i] = 0;
            }
            nextPointer->next = nullptr;
            nextPointer == nullptr;
        }
        else if (result == 1)
        {
            prevPointer = nextPointer;
            nextPointer = nextPointer->next;
        }
        else if (result == -1)
        {
            nextPointer == nullptr;
            prevPointer == nullptr;
        }
    }
}
bool setDictionary::check(int tab[])
{
    Word *nextPointer = head;
    Word *prevPointer = head;
    int result = 2;
    while (nextPointer != nullptr)
    {
        result = compare(tab, nextPointer->wordArray);
        if (result == 0)
        {
            return true;
        }
        else if (result == 1)
        {
            prevPointer = nextPointer;
            nextPointer = nextPointer->next;
        }
        else if (result == -1)
        {
            return false;
        }
    }
    return false;
}

int setDictionary::compare(int tab1[], int tab2[])
{
    if (tab1 != nullptr && tab2 != nullptr)
    {
        for (int i = 0; i < 50; i++)
        {
            if (tab1[i] > tab2[i])
            {
                return 1;
            }
            else if (tab1[i] < tab2[i])
            {
                return -1;
            }
        }
        return 0;
    }
    else {
        perror("podano jako argument nullptr");
        exit(1);
    }
}
void setDictionary::print()
{
    Word *printPtr = head;
    while (printPtr != nullptr)
    {
        std::cout << "[ ";
        for (int i = 0; i < 50; i++)
        {
            std::cout << printPtr->wordArray[i] << " ";
        }
        std::cout << "]" << std::endl;
        printPtr = printPtr->next;
    }
}