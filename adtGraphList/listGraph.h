#pragma once
#include "Lista.h"
#include <vector>
#include <utility>

class listGraph
{
    std::vector<std::pair<int, Lista*>> adjacencyList;
    int vertexAmount;

    public:

    listGraph();
    listGraph(int array[], int arraySize);
    listGraph(const listGraph& source);
    listGraph(listGraph&& source);
    ~listGraph();


    bool adjacent(int xCoordinate, int yCoordinate);
    std::vector<int> neigbours(int xCoordinate);
    void addVertex(int xValue);
    void removeVertex(int xValue);
    void addEdge(int xCoordinate, int yCoordinate, int value);
    void removeEdge(int xCoordinate, int yCoordinate);
    int getVertexValue(int xCoordinate);
    void setVertexValue(int xCoordinate, int value);
    int getEdgeValue(int xCoordinate, int yCoordinate);
    void setEdgeValue(int xCoordinate, int yCoordinate, int value);
    void print();
    void colorGraph();
    void exportToDot();
};