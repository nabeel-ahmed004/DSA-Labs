#ifndef ADJ_LIST_H
#define ADJ_LIST_H

#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

struct myList{
    int indegree=0;
    int ver;
    myList *next;
};

class adj_list {
    public:
        adj_list();
        adj_list(int vertices);
        void addEdge(int v, int w);
        void topologicalSort(const string cities[]);

    private:
        int numVertices;
        myList** my_list;
};

#endif // ADJ_LIST_H
