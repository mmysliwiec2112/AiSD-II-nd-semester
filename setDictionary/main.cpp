#include "setDictionary.h"
#include <iostream>
#include <fstream>
#include <chrono>

int main()
{
    setDictionary SD1;
    int tab[50] = {1, 2, 3};
    std::cout << "SD1.add([1, 2, 3, 0, 0, ..., 0]) -> ";
    SD1.add(tab);
    SD1.print();
    int tab2[50] = {1, 2, 3, 4};
    std::cout << "SD1.add([1, 2, 3, 4, 0, ..., 0]) -v \n";
    SD1.add(tab2);
    SD1.print();
    std::cout << "SD1.remove([1, 2, 3, 4, 0, ..., 0]) -v \n";
    SD1.remove(tab2);
    SD1.print();
    std::cout << "SD1.add([1, 2, 0, 0, 0, ..., 0]) -v \n";
    int tab3[50] = {1, 2};
    SD1.add(tab3);
    SD1.print();
    std::cout << "SD1.add([2, 1, 0, 0, 0, ..., 0]) -v \n";
    int tab4[50] = {2, 1};
    SD1.add(tab4);
    SD1.print();
    int *tab5 = nullptr;
    SD1.add(tab5);
    int tab6[] = {0};
    std::cout << "SD1.check([2, 1, 0, 0, ..., 0]) -> " << SD1.check(tab4) << std::endl;
    std::cout << "SD1.check([0, 0, 0, 0, ..., 0]) -> " << SD1.check(tab6) << std::endl;
    std::cout << "SD1.remove([1, 2, 3, 0, 0, ..., 0]) -v \n";
    SD1.remove(tab);
    SD1.print();

    //time test
    std::ofstream outFile("data.txt");
    setDictionary ttSet;
    int tempTab[50] = {0};
    srand(time(0));
    for (int i = 0; i < 1000; i++)
    {
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 49; j++)
        {
            tempTab[j] = i;
            ttSet.add(tempTab);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        outFile << i << " " << duration.count() << std::endl;
    }
    outFile.close();

    return 0;
}