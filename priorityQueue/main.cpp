#include <iostream>
#include "priorityQueue.h"
#include <fstream>
#include <chrono>


int main()
{

    int tab[10] = {1, 3, 12, 56, 90, 123, 678, 700, 708, 905};
    priorityQueue pq1(tab, 10);
    std::cout << "pq1({1,3,12,56,90,123,678,700,708,905}) -> ";
    pq1.print();

    std::cout << "pq1.add(16) -> ";
    pq1.add(16);
    pq1.print();

    for (int i = 0; i < 15; i++)
        std::cout << "pq1.pop() -> " << pq1.pop() << std::endl;


    // time test
    std::ofstream outFile("data.txt");
    int ttab[1] = {0};
    
    for (int i = 4; i < 1000; i++)
    {
        int* tempTab = new int[i];
        for(int k = 0; k < i; k ++)
        {
            tempTab[k] = k;
        }
        priorityQueue ttSet(tempTab, i);
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < i; j++)
        {
            ttSet.pop();
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        outFile << i << " " << duration.count() << std::endl;
        delete[] tempTab;
    }
    outFile.close();
    return 0;
}