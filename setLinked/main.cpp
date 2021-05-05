#include "setLinked.h"
#include <iostream>
#include <fstream>
#include <chrono>

int main()
{
    setLinked SL1;
    std::cout << "SL1.add(19) -> ";
    SL1.add(19);
    SL1.print();
    std::cout << "SL1.add(7) -> ";
    SL1.add(7);
    SL1.print();
    std::cout << "SL1.add(15) -> ";
    SL1.add(15);
    SL1.print();
    std::cout << "SL1.add(21) -> ";
    SL1.add(21);
    SL1.print();
    std::cout << "SL1.add(512) -> ";
    SL1.add(512);
    SL1.print();
    std::cout << "SL1.remove(7) -> ";
    SL1.remove(7);
    SL1.print();
    std::cout << "SL1.remove(9) -> ";
    SL1.remove(9);
    SL1.print();
    std::cout << "SL1.check(15) -> " << SL1.check(15) << std::endl;
    std::cout << "SL1.check(9) -> " << SL1.check(9) << std::endl;
    setLinked SL2;
    SL2.add(15);
    SL2.add(16);
    SL2.add(512);
    SL2.add(35);
    SL2.add(8);
    std::cout << "SL1 -> ";
    SL1.print();
    std::cout << "SL2 -> ";
    SL2.print();
    std::cout<<"SL3 -> ";
    setLinked SL3;
    SL2.print();
    // SL3.print();
    std::cout << "SL1.setIntersection(SL2) -> ";
    SL1.setIntersection(SL2).print();
    std::cout << "SL1 -> ";
    SL1.print();
    std::cout << "SL2 -> ";
    SL2.print();
    std::cout<<"SL3 -> ";
    SL3.print();
    std::cout << "SL1.setUnion(SL2) -> ";
    SL3 = SL1.setUnion(SL2);
    SL3.print();
    std::cout << "SL1 -> ";
    SL1.print();
    std::cout << "SL2 -> ";
    SL2.print();
    std::cout << "SL1.setDifference(SL2) -> ";
    SL1.setDifference(SL2).print();
    std::cout << "SL1 -> ";
    SL1.print();
    std::cout << "SL2 -> ";
    SL2.print();

    //time test
    std::ofstream outFile("data.txt");
    setLinked ttSet;
    for (int i = 0; i < 1000; i++)
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

    return 0;
}