#pragma once
#include "matrix.h"
#include <vector>

class Graph{
    Matrix* adjacencyMatrix;
    int vertexAmount;

    public:
    Graph();
    Graph(int height, int width);
    Graph(double** tab, int height, int width);
    ~Graph();
    Graph(const Graph& source);
    Graph(Graph&& source);

    bool adjacent(int xCoordinate, int yCoordinate);
    std::vector<int> neigbours(int xCoordinate);
    void addVertex(int xValue);
    void removeVertex(int xValue);
    void addEdge(int xCoordinate, int yCoordinate, int value);
    void removeEdge(int xCoordinate, int yCoordinate);
    double getVertexValue(int xCoordinate);
    void setVertexValue(int xCoordinate, int value);
    double getEdgeValue(int xCoordinate, int yCoordinate);
    void setEdgeValue(int xCoordinate, int yCoordinate, int value);
    void exportToDot();
    

    friend std::ostream& operator<<(std::ostream &stream, Graph& source);
};