#ifndef ADJ_MATRIX_H
#define ADJ_MATRIX_H

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class adj_matrix
{
    public:
        adj_matrix(int vertices, const bool* adjMatrix, const std::string* vertexNamesArray);
        void bfs(const string& startVertex);// Breadth-First Search

    private:
        int numvert;
        vector<vector<bool>> adjacencyMatrix;
        vector<string> vertexNames;
};

#endif // ADJ_MATRIX_H
