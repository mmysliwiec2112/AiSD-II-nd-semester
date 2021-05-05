#include "listGraph.h"
#include <iostream>

int main(){

    std::cout<<"listGraph() lg1 ->"<<std::endl;
    listGraph lg1;

    int tab[] = {1, 2 ,3};
    std::cout<<"listGraph({1, 2, 3}) lg2 ->"<<std::endl;
    listGraph lg2(tab, 3);

    std::cout<<"listGraph(lg2) lg3 ->"<<std::endl;
    listGraph lg3(lg2);

    std::cout<<"listGraph(std::move(lg1)) lg4 ->"<<std::endl;
    listGraph lg4(std::move(lg1));

    std::cout<<"lg2.addEdge(1,2,2) ->"<<std::endl;
    lg2.addEdge(1,2,2);
    lg2.print();

    std::cout<<"lg2.addEdge(1,3,3) ->"<<std::endl;
    lg2.addEdge(1,3,3);
    lg2.print();

    std::cout<<"lg2.addEdge(2,3,3) ->"<<std::endl;
    lg2.addEdge(2,3,3);
    lg2.print();

    std::cout<<"lg2.addEdge(2,2,3) ->"<<std::endl;
    lg2.addEdge(2,2,3);

    std::cout<<"lg2.addEdge(1,1,3) ->"<<std::endl;
    lg2.addEdge(1,1,3);

    std::cout<<"lg2.addEdge(2,1,3) ->"<<std::endl;
    lg2.addEdge(2,1,3);

    std::cout<<"lg2.addEdge(3,1,3) ->"<<std::endl;
    lg2.addEdge(3,1,3);

    std::cout<<"lg2.addEdge(3,2,3) ->"<<std::endl;
    lg2.addEdge(3,2,3);
    lg2.print();

    std::cout<<"lg2.addVertex(5) -> "<<std::endl;
    lg2.addVertex(5);
    lg2.print();


    std::cout<<"lg2.addEdge(5,1,3) ->"<<std::endl;
    lg2.addEdge(3,1,3);

    // std::cout<<"lg2.addEdge(3,2,3) ->"<<std::endl;
    // lg2.addEdge(3,2,3);
    // lg2.print();

    std::cout<<"lg2.removeVertex(5) -> "<<std::endl;
    lg2.removeVertex(3);
    lg2.print();

    lg2.exportToDot();
    lg2.colorGraph();
}