#include "listGraph.h"
#include <iostream>
#include <utility>
#include <fstream>

listGraph::listGraph()
{
    for (int i = 0; i < 3; i++)
    {
        std::pair<int, Lista *> vertex;
        vertex.first = i;
        vertex.second = new Lista;
        adjacencyList.push_back(vertex);
    }
    vertexAmount = 3;
}
listGraph::listGraph(int array[], int arraySize) : vertexAmount(arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        std::pair<int, Lista *> vertex;
        vertex.first = array[i];
        vertex.second = new Lista;
        adjacencyList.push_back(vertex);
    }
}
listGraph::listGraph(const listGraph &source)
{
    if (this != &source)
    {
        vertexAmount = source.vertexAmount;
        for (int i = 0; i < vertexAmount; i++)
        {
            std::pair<int, Lista *> vertex;
            vertex.first = source.adjacencyList.at(i).first;
            vertex.second = new Lista;
            *vertex.second = *source.adjacencyList.at(i).second;
            adjacencyList.push_back(vertex);
        }
    }
}
listGraph::listGraph(listGraph &&source)
{
    if (this != &source)
    {
        vertexAmount = source.vertexAmount;
        for (int i = 0; i < vertexAmount; i++)
        {
            std::pair<int, Lista *> vertex;
            vertex.first = source.adjacencyList.at(i).first;
            vertex.second = new Lista;
            *vertex.second = *source.adjacencyList.at(i).second;
            adjacencyList.push_back(vertex);
        }
        for (int i = 0; i < vertexAmount; i++)
        {
            source.adjacencyList.at(i).second->clear();
            delete source.adjacencyList.at(i).second;
        }
        source.vertexAmount = 0;
    }
}
listGraph::~listGraph()
{
    for (int i = 0; i < vertexAmount; i++)
    {
        adjacencyList.at(i).second->clear();
        delete adjacencyList.at(i).second;
    }
}
bool listGraph::adjacent(int xCoordinate, int yCoordinate)
{
    if (adjacencyList.at(xCoordinate - 1).second->Locate(xCoordinate - 1, yCoordinate) != nullptr)
        return true;
}
void listGraph::addVertex(int xValue)
{
    std::pair<int, Lista *> vertex;
    vertex.first = xValue;
    vertex.second = new Lista;
    adjacencyList.push_back(vertex);
}
void listGraph::removeVertex(int xValue)
{
    delete adjacencyList.at(xValue - 1).second;
    adjacencyList.erase(adjacencyList.begin() + xValue - 1);
    for (int i = 0; i < vertexAmount; i++)
    {
        adjacencyList.at(i).second->Delete(adjacencyList.at(i).second->LocateNode(xValue));
    }
}
void listGraph::addEdge(int xCoordinate, int yCoordinate, int value)
{
    bool isPresent = false;
    for (int i = 0; i < adjacencyList.size(); i++)
    {
        if (adjacencyList.at(i).first == yCoordinate)
            isPresent = true;
    }
    if (isPresent && nullptr == adjacencyList.at(xCoordinate - 1).second->LocateNode(yCoordinate))
    {
        adjacencyList.at(xCoordinate - 1).second->Insert(value, nullptr, yCoordinate);
    }
}
int listGraph::getVertexValue(int xCoordinate)
{
    return adjacencyList.at(xCoordinate - 1).first;
}
void listGraph::setVertexValue(int xCoordinate, int value)
{
    adjacencyList.at(xCoordinate - 1).first = value;
}
int listGraph::getEdgeValue(int xCoordinate, int yCoordinate)
{
    return adjacencyList.at(xCoordinate - 1).second->LocateNode(yCoordinate)->element;
}
void listGraph::setEdgeValue(int xCoordinate, int yCoordinate, int value)
{
    adjacencyList.at(xCoordinate - 1).second->LocateNode(yCoordinate)->element = value;
}
void listGraph::print()
{
    for (auto it = 0; it < adjacencyList.size(); it++)
    {
        std::cout << adjacencyList.at(it).first << " -> ";
        adjacencyList.at(it).second->print();
    }
}
void listGraph::exportToDot()
{
    std::ofstream outFile("graph.txt");
    outFile << " digraph G {" << std::endl;
    for (int i = 0; i < vertexAmount; i++)
    {
        auto node = adjacencyList.at(i).second->First();
        if( node == nullptr ){
            outFile << adjacencyList.at(i).first <<std::endl;
        }
        while (node != nullptr)
        {
            outFile << adjacencyList.at(i).first << " -> "<< node -> node <<  " [label = \"" << node -> element << "\"];" << std::endl;
            node = adjacencyList.at(i).second->Next(node);
        }

    }
    outFile << "}";
}
void listGraph::colorGraph()
{
    if (vertexAmount != 0)
    {
        int *coloredVertexes = new int[vertexAmount];
        bool *availableColors = new bool[vertexAmount];
        coloredVertexes[0] = 0;

        for (int i = 0; i < vertexAmount; i++)
        {
            if (i != 0)
                coloredVertexes[i] = -1;
            availableColors[i] = false;
        }

        for (int i = 0; i < vertexAmount; i++)
        {
            auto node = adjacencyList.at(i).second->First();
            int iterator = 0;
            while (node != nullptr)
            {
                if (coloredVertexes[iterator] != -1)
                {
                    availableColors[coloredVertexes[iterator]] = true;
                }
                iterator++;
                node = adjacencyList.at(i).second->Next(node);
            }
            for (int color = 0; color < vertexAmount; color++)
            {
                if (availableColors[color] == false)
                {
                    coloredVertexes[i] = color;
                    break;
                }
            }
            iterator = 0;
            while (node != nullptr)
            {
                if (coloredVertexes[iterator] != -1)
                {
                    availableColors[coloredVertexes[iterator]] = false;
                }
                node = adjacencyList.at(i).second->Next(node); 
                iterator++;
            }
            iterator = 0;
            for (int u = 0; u < vertexAmount; u++)
                std::cout << "Vertex " << u << " --->  Color " << coloredVertexes[u] << std::endl;
            delete[] availableColors;
            delete[] coloredVertexes;
        }
    }
}