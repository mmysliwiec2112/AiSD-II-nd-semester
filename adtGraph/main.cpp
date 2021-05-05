#include "graph.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>


int main()
{
    Graph graph1;
    double **tab;
    tab = new double *[5];
    for (int i = 0; i < 5; i++)
    {
        tab[i] = new double[5];
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0)
                tab[i][j] = (double)j;
            else if (j == 0)
                tab[i][0] = (double)i;
            else
                tab[i][j] = 0.0;
        }
    }
    Graph graph2(tab, 5, 5);
    std::cout << graph2;

    Graph graph3(graph2);
    graph2.addVertex(3);
    std::cout << "graph2.addVertex(3) -> \n"
              << graph2;

    graph2.addEdge(1, 2, 5);
    std::cout << "graph2.addEdge(1, 2, 5); -> \n"
              << graph2;

    graph2.addEdge(4, 3, 3);
    std::cout << "graph2.addEdge(4, 3, 3); -> \n"
              << graph2;

    graph2.addEdge(3, 2, 2);
    std::cout << "graph2.addEdge(3, 2, 2); -> \n"
              << graph2;

    graph2.addEdge(2, 1, 4);
    std::cout << "graph2.addEdge(10, 1, 4); -> \n"
              << graph2;

    graph2.addEdge(2, 2, 3);
    std::cout << "graph2.addEdge(10, 1, 4); -> \n"
              << graph2;

    graph2.addEdge(4, 2, 8);
    std::cout << "graph2.addEdge(10, 1, 4); -> \n"
              << graph2;

    std::cout<<"exporting to dot"<<std::endl;
    graph2.exportToDot();

    graph2.removeVertex(3);
    std::cout << "graph2.removeVertex(3) -> \n"
              << graph2;

    graph2.removeEdge(1, 2);
    std::cout << "graph2.removeEdge(1, 2); -> \n"
              << graph2;

    graph2.addVertex(17);
    std::cout << "graph2.addVertex(17) -> \n"
              << graph2;

    graph2.removeVertex(3);
    std::cout << "graph2.removeVertex(10) -> \n"
              << graph2;

    graph2.addVertex(8);
    std::cout << "graph2.addVertex(8) -> \n"
              << graph2;
    std::cout << "";
    auto temp = graph2.neigbours(3);

    std::cout << "graph2.neigbours(3) -> ";
    for (auto it = 0; it < temp.size(); it++)
    {
        std::cout << temp.at(it) << " ";
    }
    std::cout << std::endl;
    std::cout << "";



    // time test
    std::ofstream outFile("data.txt");
    for (int i = 4; i < 1000; i++)
    {
        Graph ttGraph(tab, 5, 5);
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < i; j++)
        {
            ttGraph.addEdge(1, 1, j);
        }
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        outFile << i << " " << duration.count() << std::endl;
    }

    for (int j = 0; j < 5; j++)
        delete[] tab[j];
    delete[] tab;
}