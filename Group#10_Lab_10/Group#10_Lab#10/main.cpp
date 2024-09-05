#include <iostream>
#include "adj_matrix.h"
#include "adj_list.h"

using namespace std;

int main()
{
    int noOfVertex = 15;  // Update the number of vertices
    bool mat[noOfVertex][noOfVertex]= { 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 };
    //String arrays contains the name of the Cities...
    string cities[noOfVertex] = {"Kuri", "ChataBakhtawar", "Alipur", "Taramri", "Chirah", "Nilore", "ThandaPani", "Mohara", "Jagiot", "Malot", "Athal", "PindBhegwal", "Bharakho", "ChakShahzad", "BaniGala"};

    // Create a graph with 15 vertices
    adj_matrix g(noOfVertex, &mat[0][0], &cities[0]);

    // Perform BFS starting from "Nilore"
    cout << "BFS starting from 'Nilore':\n";
    g.bfs("Nilore");
    cout<<"\n";
    string Cities[noOfVertex] = {"Nilore","Chirah","Thanda Paani","Mohara","Ali Pur","Pind Bhagwal","Taramri","Jagiot","Athal","Chatta Bakhtawar","Malot","Bhara Kahu","Kuri","Chak Shahazad","Bani Gala"};
    adj_list list_topoligical(15);
    list_topoligical.addEdge(0,1);
    list_topoligical.addEdge(0,2);
    list_topoligical.addEdge(0,3);
    list_topoligical.addEdge(2,4);
    list_topoligical.addEdge(3,5);
    list_topoligical.addEdge(4,6);
    list_topoligical.addEdge(4,7);
    list_topoligical.addEdge(5,8);
    list_topoligical.addEdge(6,9);
    list_topoligical.addEdge(7,5);
    list_topoligical.addEdge(8,11);
    list_topoligical.addEdge(9,12);
    list_topoligical.addEdge(9,13);
    list_topoligical.addEdge(10,8);
    list_topoligical.addEdge(11,14);
    list_topoligical.addEdge(12,10);
    list_topoligical.addEdge(13,14);
    // Perform topological sort
    list_topoligical.topologicalSort(Cities);
    cout << '\n';
}
