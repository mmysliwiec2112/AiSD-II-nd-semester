#include"setSimple.h"
#include<iostream>
#include <fstream>
#include <chrono>
int main(){
    int tab1[] = {1, 59, 78, 189, 890};
    std::cout<<"set1 -> ";
    setSimple set1 (tab1);
    set1.print();
    std::cout<<"set1.add(999) -> ";
    set1.add(999);
    set1.print();
    std::cout<<"set1.remove(-1) (should print an error)"<<std::endl;
    set1.remove(-1);
    std::cout<<"set1.remove(59) -> ";
    set1.remove(59);
    set1.print();
    std::cout<<"set1.check(999) -> "<<set1.check(999)<<std::endl;
    std::cout<<"set1.check(0) -> "<<set1.check(0)<<std::endl;
    int tab2[] = {2, 15, 49, 78, 100, 890};
    setSimple set2 (tab2);
    std::cout<<"set2 -> ";
    set2.print();
    std::cout<<"set3 = set1.setUnion(set2) -> ";
    setSimple set3 = set1.setUnion(set2);
    set3.print();
    std::cout<<"set4 = set1.setIntersection(set2) -> ";
    setSimple set4 = set1.setIntersection(set2);
    set4.print();
    std::cout<<"set5 = set1.setDifference(set2) -> ";
    setSimple set5 = set1.setDifference(set2);
    set5.print();


    //time test
    std::ofstream outFile("data.txt");
    int ttab[1] = {0};
    setSimple ttSet(ttab);
    for(int i = 0; i < 1000; i++)
    {       
        auto start = std::chrono::high_resolution_clock::now();
        for(int j = 0; j < 500; j++){
            ttSet.add(i);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        outFile<<i<<" "<<duration.count()<<std::endl;
    }
    outFile.close();

    return 0;
}