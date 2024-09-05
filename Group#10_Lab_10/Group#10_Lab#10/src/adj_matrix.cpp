#include "adj_matrix.h"
using namespace std;

adj_matrix::adj_matrix(int vertices, const bool* adjMatrix, const std::string* vertexNamesArray)
{
    numvert=vertices;
    adjacencyMatrix.resize(vertices, vector<bool>(vertices));
    int i, j;
    for(i=0; i<vertices; ++i)
    {
        for(j=0; j<vertices; ++j)
        {
            adjacencyMatrix[i][j] = adjMatrix[i * vertices + j];
        }
    }

    vertexNames.assign(vertexNamesArray, vertexNamesArray+vertices);
}

void adj_matrix::bfs(const string& startVertex)// Breadth-First Search
{
    int startIndex = -1; // Default value indicating not found

    // Find the index of the start vertex
    for (int i = 0; i < numvert; ++i)
    {
        if (vertexNames[i] == startVertex)
        {
            startIndex = i;
            break; // Stop searching once found
        }
    }

    if (startIndex == -1)
    {
        std::cerr << "Start vertex not found.\n";
        return;
    }

    vector<bool> visited(numvert, false);
    queue<int> queue1;
    visited[startIndex] = true;
    queue1.push(startIndex);

    while (!queue1.empty())
    {
        // Dequeue a vertex from the queue and print it
        int currentVertex = queue1.front();
        cout << vertexNames[currentVertex] << " ";
        queue1.pop();

        // Get all adjacent vertices of the dequeued vertex
        for (int adjacent = 0; adjacent < numvert; ++adjacent)
        {
            if (adjacencyMatrix[currentVertex][adjacent] && !visited[adjacent])
            {
                visited[adjacent] = true;
                queue1.push(adjacent);
            }
        }
    }
    cout << '\n';
}
