#include "setHashed.h"
#include <iostream>
#include <fstream>
#include <chrono>

int main()
{

    setHashed sh1(5);
    for (int i = 0; i < 40; i++)
    {
        sh1.add(i);
    }
    std::cout << "sh1.add(1 - 40) -v " << std::endl;
    sh1.print();

    std::cout << "sh1.remove(0) -v" << std::endl;
    sh1.remove(0);
    sh1.print();

    std::cout << "sh1.check(1) -> ";
    std::cout << sh1.check(1) << std::endl;
    std::cout << "sh1.check(0) -> ";
    std::cout << sh1.check(0) << std::endl;

    setHashed sh2(5);
    for (int i = 0; i < 20; i++)
    {
        sh2.add(i * 2);
    }
    std::cout << "sh2.add(2 - 22) -v " << std::endl;
    sh2.print();

    std::cout << "sh1.setUnion(sh2) -v " << std::endl;
    sh1.setUnion(sh2).print();

    std::cout << "sh1.setIntersection(sh2) -v " << std::endl;
    sh1.setIntersection(sh2).print();

    std::cout << "sh1.setDifference(sh2) -v " << std::endl;
    sh1.setDifference(sh2).print();

    std::cout << "sh3(sh2) -v " << std::endl;
    setHashed sh3(sh2);
    sh3.print();

    std::cout << "sh2.isEqual(sh3) -> " << sh2.isEqual(sh3) << std::endl;


    //time test
    std::ofstream outFile("data.txt");
    for (int i = 1; i < 10000; i++)
    {
        setHashed ttSet(1000);
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < i; j++)
        {
            ttSet.add(j);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        outFile << i << " " << duration.count() << std::endl;
        // ttSet.~ttSet();
    }
    outFile.close();

    return 0;
}