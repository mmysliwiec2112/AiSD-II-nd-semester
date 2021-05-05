#include "graph.h"
#include "matrix.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <random>
#include <utility>

Graph::Graph()
{
    adjacencyMatrix = new Matrix(3, 3);
    for (int i = 0; i < 3; i++)
    {
        adjacencyMatrix->set_element(0, i, i);
        adjacencyMatrix->set_element(i, 0, i);
    }
    vertexAmount = 3;
}
Graph::Graph(int height, int width)
{
    adjacencyMatrix = new Matrix(width, height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 1; j < width; j++)
        {
            if (i == 0)
            {
                adjacencyMatrix->set_element(j, i, j);
                adjacencyMatrix->set_element(i, j, j);
            }
            else
                adjacencyMatrix->set_element(j, i, 0);
        }
    }
    vertexAmount = height;
}
Graph::Graph(double **tab, int height, int width)
{
    adjacencyMatrix = new Matrix(width, height);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            adjacencyMatrix->set_element(j, i, tab[i][j]);
        }
    }
    vertexAmount = height;
}
Graph::~Graph()
{
    delete adjacencyMatrix;
}
Graph::Graph(const Graph &source)
{
    if (this != &source)
    {
        adjacencyMatrix = new Matrix(source.adjacencyMatrix->row_lenght(), source.adjacencyMatrix->column_height());
        for (int i = 0; i < source.adjacencyMatrix->row_lenght(); i++)
        {
            for (int j = 0; j < source.adjacencyMatrix->column_height(); j++)
            {
                adjacencyMatrix->set_element(j, i, source.adjacencyMatrix->get_element(i, j));
            }
        }
        vertexAmount = source.vertexAmount;
    }
}
Graph::Graph(Graph &&source)
{
    if (this != &source)
    {
        vertexAmount = source.vertexAmount;
        adjacencyMatrix = new Matrix(source.adjacencyMatrix->row_lenght(), source.adjacencyMatrix->column_height());
        for (int i = 0; i < source.adjacencyMatrix->row_lenght(); i++)
        {
            for (int j = 0; j < source.adjacencyMatrix->column_height(); j++)
            {
                adjacencyMatrix->set_element(j, i, source.adjacencyMatrix->get_element(i, j));
            }
        }
        source.vertexAmount = 0;
        delete source.adjacencyMatrix;
    }
}

bool Graph::adjacent(int xCoordinate, int yCoordinate)
{
    return adjacencyMatrix->get_element(xCoordinate, yCoordinate) > 0 ? true : false;
}
std::vector<int> Graph::neigbours(int xCoordinate)
{
    std::vector<int> neigbours(0);
    for (int i = 1; i < adjacencyMatrix->column_height(); i++)
    {
        if (adjacencyMatrix->get_element(xCoordinate, i) > 0.0)
        {
            neigbours.push_back(i);
        }
    }
    return neigbours;
}
void Graph::addVertex(int xValue)
{
    if (vertexAmount == adjacencyMatrix->column_height())
    {
        Matrix *temp = new Matrix(vertexAmount + 1, vertexAmount + 1);
        for (int i = 0; i < vertexAmount; i++)
        {
            for (int j = 0; j < vertexAmount; j++)
            {
                temp->set_element(i, j, adjacencyMatrix->get_element(i, j));
                temp->set_element(j, i, adjacencyMatrix->get_element(j, i));
            }
        }
        temp->set_element(vertexAmount, 0, xValue);
        temp->set_element(0, vertexAmount, xValue);
        delete adjacencyMatrix;
        adjacencyMatrix = temp;
    }
    else
    {
        adjacencyMatrix->set_element(vertexAmount, 0, xValue);
        adjacencyMatrix->set_element(0, vertexAmount, xValue);
    }
    vertexAmount++;
}

void Graph::removeVertex(int xValue)
{
    for (int i = 0; i < adjacencyMatrix->row_lenght(); i++)
    {
        if (adjacencyMatrix->get_element(i, 0) == xValue)
        {
            for (int j = 0; j < vertexAmount; j++)
            {
                adjacencyMatrix->set_element(i, j, 0);
                adjacencyMatrix->set_element(j, i, 0);
            }
            i++;
            for (; i < vertexAmount; i++)
            {
                for (int j = 0; j < vertexAmount; j++)
                {
                    adjacencyMatrix->set_element(i - 1, j, adjacencyMatrix->get_element(i, j));
                    adjacencyMatrix->set_element(j, i - 1, adjacencyMatrix->get_element(j, i));
                }
            }
            for (int j = 0; j < vertexAmount; j++)
            {
                adjacencyMatrix->set_element(j, vertexAmount - 1, 0);
                adjacencyMatrix->set_element(vertexAmount - 1, j, 0);
            }
        }
    }
    --vertexAmount;
}

void Graph::addEdge(int xCoordinate, int yCoordinate, int value)
{
    adjacencyMatrix->set_element(xCoordinate, yCoordinate, value);
    adjacencyMatrix->set_element(yCoordinate, xCoordinate, value);
}

void Graph::removeEdge(int xCoordinate, int yCoordinate)
{
    adjacencyMatrix->set_element(xCoordinate, yCoordinate, 0);
    adjacencyMatrix->set_element(yCoordinate, xCoordinate, 0);
}
double Graph::getVertexValue(int xCoordinate)
{
    return adjacencyMatrix->get_element(xCoordinate, 0);
}
void Graph::setVertexValue(int xCoordinate, int value)
{
    adjacencyMatrix->set_element(xCoordinate, 0, value);
    adjacencyMatrix->set_element(0, xCoordinate, value);
}
double Graph::getEdgeValue(int xCoordinate, int yCoordinate)
{
    return adjacencyMatrix->get_element(xCoordinate, yCoordinate);
}
void Graph::setEdgeValue(int xCoordinate, int yCoordinate, int value)
{
    adjacencyMatrix->set_element(xCoordinate, yCoordinate, value);
    adjacencyMatrix->set_element(yCoordinate, xCoordinate, value);
}
void Graph::exportToDot()
{
    std::ofstream outFile("graph.txt");
    outFile << " digraph G {" << std::endl;
    for (int i = 1; i < vertexAmount; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (adjacencyMatrix->get_element(i, j) != 0)
            {
                outFile << adjacencyMatrix->get_element(i, 0) << " -> " << adjacencyMatrix->get_element(j, 0) << " [label = \"" << adjacencyMatrix->get_element(j, i) << "\"];" << std::endl;
                outFile << adjacencyMatrix->get_element(j, 0) << " -> " << adjacencyMatrix->get_element(i, 0) << " [label = \"" << adjacencyMatrix->get_element(j, i) << "\"];" << std::endl;
            }
        }
    }
    outFile << "}";
}

std::ostream &operator<<(std::ostream &stream, Graph &source)
{

    for (int i = 0; i < source.adjacencyMatrix->column_height(); i++)
    {
        stream << "|";
        for (int j = 0; j < source.adjacencyMatrix->row_lenght(); j++)
        {
            stream << std::setw(3);
            stream << source.adjacencyMatrix->get_element(j, i);
            if (j < source.adjacencyMatrix->row_lenght() - 1)
                stream << " ";
        }
        stream << std::setw(3);
        stream << "|" << std::endl;
    }
    stream << std::endl
           << std::endl;
    return stream;
}

bool Graph::traverse(int start, std::vector<bool> &visited, std::vector<int> &nodes)
{
    visited[start] = true;

    if (nodes.size() == vertexAmount)
    {
        nodes.push_back(start);
        return true;
    }
    std::vector<int> to_visit;
    to_visit.push_back(0);
    std::vector<int> vectorNeighbours = neigbours(start);

    for (int it = 0; it < vectorNeighbours.size(); it++)
    {
        if (!visited[vectorNeighbours.at(it)])
        {
            to_visit.push_back(vectorNeighbours.at(it));
        }
    }
    for (int i = 0; i < to_visit.size(); i++)
    {
        std::cout << to_visit.at(i) << " -> ";
    }
    std::cout<<std::endl;
    if (to_visit.size() <= 1)
    {
        return false;
    }
    if (to_visit.size() <= 4)
    {
        warnsdorffs_sort(to_visit);
    }
    else
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(to_visit.begin() + 1, to_visit.end(), g);
    }

    nodes.push_back(start);
    for (int i = 1; i < to_visit.size(); i++)
    {
        if (traverse(to_visit.at(i), visited, nodes))
            return true;
    }
}

void Graph::warnsdorffs_sort(std::vector<int> &to_visit)
{
    std::vector<std::pair<int, int>> nodeMovesAmount;
    for (int i = 1; i < to_visit.size(); i++)
    {
        std::pair<int, int> temp;
        temp.first = neigbours(to_visit.at(i)).size();
        temp.second = to_visit.at(i);
        nodeMovesAmount.push_back(temp);
    }
    std::sort(nodeMovesAmount.begin() + 1, nodeMovesAmount.end());
    for (int i = 1; i < to_visit.size(); i++)
    {
        to_visit[i] = nodeMovesAmount.at(i - 1).second;
    }
}

//     // for (int i = 1; i < nodes.size(); i++)
//     // {
//     //     // std::cout << nodes.at(i) << " -> ";
//     // }
//     // // std::cout<<std::endl;
//     if(start > to_visit.size()) break;
//     start++;