#include "graph.h"
#include <vector>
#include <cmath>
#include <utility>
#include <list>
#include <fstream>

struct coordinates
{
    int x;
    int y;
    int vertexCoordinate;
};

int MOVE_OFFSETS[8][2] = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2}};
std::vector<coordinates> legalMoves(coordinates vertex, int boardSize)
{
    std::vector<coordinates> legal_moves;
    int squareAmount = pow(boardSize, 2) + 1;
    for (int i = 0; i < 8; i++)
    {
        int move_row = vertex.x + MOVE_OFFSETS[i][0];
        int move_col = vertex.y + MOVE_OFFSETS[i][1];
        if ((1 <= move_row && move_row <= boardSize) && (1 <= move_col && move_col <= boardSize))
        {

            coordinates temp;

            temp.x = move_row;
            temp.y = move_col;
            temp.vertexCoordinate = (move_row - 1) * boardSize + move_col;
            // std::cout<<"x = "<<temp.x<<std::endl;
            // std::cout<<"y = "<<temp.y<<std::endl;
            // std::cout<<"vertex coordinate = "<<temp.vertexCoordinate<<std::endl;
            legal_moves.push_back(temp);
        }
    }
    return legal_moves;
}
Graph buildGraph(int boardSize)
{
    int squareAmount = pow(boardSize, 2) + 1;
    Graph board(squareAmount, squareAmount);
    coordinates temp;
    for (int row = 1; row < boardSize; row++)
    {
        for (int col = 1; col < boardSize; col++)
        {
            temp.x = row;
            temp.y = col;
            temp.vertexCoordinate = (row - 1) * boardSize + col;
            std::vector<coordinates> dest_coord = legalMoves(temp, boardSize);
            for (int i = 0; i < dest_coord.size(); ++i)
            {
                board.addEdge(temp.vertexCoordinate, dest_coord.at(i).vertexCoordinate, 1.0);
            }
        }
    }
    return board;
}
void exportToDot(std::vector<int> nodes)
{
    std::ofstream outFile("path.txt");
    outFile << " digraph G {" << std::endl;
    for (int i = 1; i < nodes.size() - 1; ++i)
    {
        outFile << nodes.at(i) << " -> " << nodes.at(i + 1) << " [label = \"" << i << "\"];" << std::endl;
    }
    outFile << "}";
}

int main()
{
    int boardSize = 5;
    Graph board(std::move(buildGraph(boardSize)));
    std::cout << board << std::endl;
    board.exportToDot();
    std::vector<bool> visited;
    std::vector<int> nodes;
    for (int i = 0; i < boardSize * boardSize; i++)
    {
        visited.push_back(false);
    }
    for (int i = 0; i < 1; i++)
    {
        nodes.push_back(i);
    }
    int start = 1;
    int pathSize = 0;
    while (pathSize < (boardSize * boardSize - 2))
    {
        if (board.traverse(start, visited, nodes))
        {
            std::cout << std::endl;
            for (int i = 1; i < nodes.size(); i++)
            {
                std::cout << nodes.at(i) << " -> ";
            }
            std::cout << "size: " << nodes.size() << std::endl;
        }
        start++;
        pathSize = nodes.size();
        if (pathSize != (boardSize * boardSize + 1))
        {
            nodes.clear();
            nodes.push_back(0);
        }
        visited.clear();
        for (int i = 0; i < boardSize * boardSize; i++)
        {
            visited.push_back(false);
        }
        if (start == boardSize * boardSize + 1)
        {
            start = 1;
            visited.clear();
            for (int i = 0; i < boardSize * boardSize; i++)
            {
                visited.push_back(false);
            }
            nodes.clear();
            nodes.push_back(0);
        }
    }
    std::cout << "first true path" << std::endl;
    for (int i = 1; i < nodes.size(); i++)
    {
        std::cout << nodes.at(i) << " -> ";
    }
    exportToDot(nodes);
}