#include "adj_list.h"

adj_list::adj_list() {}

adj_list::adj_list(int vertices)
{
    numVertices=vertices;
    my_list= new myList*[vertices];

    for(int i=0;i<vertices;i++)
        my_list[i]=NULL;
}
void adj_list::addEdge(int v, int w)
{
    myList* temp = new myList;
    temp->next = my_list[v];
    temp->ver = w;
    my_list[v] = temp;
    if (my_list[w] != NULL)
    {
        my_list[w]->indegree++;
    }
}
void adj_list::topologicalSort(const string cities[])
{
    queue<int> q;
    vector<int> indegree(numVertices, 0);  // New vector to store indegree of each vertex

    // Calculate indegree for each vertex
    for (int i = 0; i < numVertices; ++i)
    {
        myList* temp = my_list[i];
        while (temp != NULL)
        {
            indegree[temp->ver]++;
            temp = temp->next;
        }
    }

    // Enqueue vertices with indegree 0
    for (int i = 0; i < numVertices; ++i)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    cout << "Topological Sort Order:\n";
    while (!q.empty())
    {
        int vertexIndex = q.front();
        cout << cities[vertexIndex] << " ";
        q.pop();

        // Update indegree and enqueue adjacent vertices
        myList* temp = my_list[vertexIndex];
        while (temp != NULL)
        {
            indegree[temp->ver]--;
            if (indegree[temp->ver] == 0)
                q.push(temp->ver);
            temp = temp->next;
        }
    }
    cout << '\n';
}
