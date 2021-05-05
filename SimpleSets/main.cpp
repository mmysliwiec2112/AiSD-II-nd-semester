#include "setSimpleNM.h"
#include "setSimpleEven.h"
#include <iostream>
#include <fstream>
#include <chrono>

int main()
{
    // simple set for numbers from n to m
    std::cout<<"\n------setSimpleNM------\n"<<std::endl;
    int n = 10;
    int m = 50;
    int tab[5] = {15, 16, 17, 20, 35};
    std::cout << "ssnm(10, 50, {15, 16, 17, 20, 35})) -> ";
    setSimpleNM ssnm(10, 50, tab);
    ssnm.print();
    std::cout << "ssnm.add(24) -> ";
    ssnm.add(24);
    ssnm.print();
    std::cout << "ssnm.remove(35) -> ";
    ssnm.remove(35);
    ssnm.print();
    int tab2[5] = {13, 17, 18, 20, 35};
    std::cout << "ssnm2(10, 50, {13, 17, 18, 20, 35})) -> ";
    setSimpleNM ssnm2(10, 50, tab2);
    ssnm2.print();
    std::cout << "ssnm2.add(24) -> ";
    ssnm2.add(24);
    ssnm2.print();
    std::cout << "ssnm = ->";
    ssnm.print();
    std::cout << "ssnm2 = ->";
    ssnm2.print();
    std::cout << "ssnm.setUnion(ssnm2) -> ";
    ssnm.setUnion(ssnm2).print();
    std::cout << "ssnm.setIntersection(ssnm2) -> ";
    ssnm.setIntersection(ssnm2).print();
    std::cout << "ssnm.setDifference(ssnm2) -> ";
    ssnm.setDifference(ssnm2).print();

    // time test
    std::ofstream outFile("dataNM.txt");
    int ttab[1] = {0};
    setSimpleNM ttSet(1000, 5000, ttab);
    for (int i = 1000; i < 5000; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < i; j++)
        {
            ttSet.add(i);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        outFile << i << " " << duration.count() << std::endl;
    }
    outFile.close();

    //simple set for even numbers
    std::cout<<"\n------setSimpleEven------\n"<<std::endl;
    n = 5;
    m = 15;
    int tab3[5] = {6, 8, 10, 12, 14};
    setSimpleEven sse(n,m, tab3);
    std::cout << "sse = {6, 8, 10, 12, 14} -> ";
    sse.print();
    int tab4[3] = {8,12,14};
    setSimpleEven sse2(n,m, tab4);
    std::cout << "sse2 = {8, 12, 14} -> ";
    sse2.print();
    std::cout << "sse.remove(12) -> ";
    sse.remove(12);
    sse.print();
    std::cout<< "sse2.add(6) -> ";
    sse2.add(6);
    sse2.print();
    std::cout<< "sse2.remove(6) -> ";
    sse2.remove(6);
    sse2.print();
    std::cout<< "sse -> ";
    sse.print();
    std::cout<< "sse2 -> ";
    sse2.print();
    std::cout<< "sse.setUnion(sse2) -> ";
    sse.setUnion(sse2).print();
    std::cout<< "sse.setsetIntersection(sse2) -> ";
    sse.setIntersection(sse2).print();
    std::cout<< "sse.setDifference(sse2) -> ";
    sse.setDifference(sse2).print();

    // time test
    std::ofstream outFileE("dataEven.txt");
    int ttabE[1] = {0};
    setSimpleEven ttSetE(1000, 5000, ttabE);
    for (int i = 1000; i < 5000; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < i; j++)
        {
            ttSetE.add(i);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        outFileE << i << " " << duration.count() << std::endl;
    }
    outFileE.close();


    
    return 0;
}