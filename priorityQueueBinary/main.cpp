#include "binaryHeap.h"
#include "priorityQueueBinary.h"
#include <iostream>

int main(){
    int tab[6] = {12, 11, 13, 5, 6, 7 };
    std::cout<<"bh1({12, 11, 13, 5, 6, 7 }, 6) -> ";
    binaryHeap bh1(tab, 6);
    bh1.print();

    std::cout<<"bh1.add(15) -> ";
    bh1.add(15);
    bh1.print();

    std::cout<<"bh1.remove(15) -> ";
    bh1.remove(bh1.elementId(15));
    bh1.print();

    binaryHeap bh2(tab, 6);
    bh2.print();
    std::cout<<"bh2 = bh1 -> ";
    bh2 = bh1;
    bh2.print();


    std::cout<<"pqb1({12, 11, 13, 5, 6, 7 }, 6) -> ";
    priorityQueueBinary pqb1(tab, 6);
    pqb1.print();
    
    std::cout<<"pqb1.add(23) -> ";
    pqb1.add(23);
    pqb1.print();

    std::cout<<"pqb1.pop() -> "<<pqb1.pop()<<std::endl;
    pqb1.print();
}