#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    int i;
    BST <int> tree;
    double a, search;
    for(i=0; i<100; i++)
    {
        a = rand()%1000;
        tree.insert(a);
    }
    cout << " ~ RANDOM VALUES HAVE BEEN INSERTED IN BST ~" << endl << endl ;
    cout<<"----------------------------------------------- \n";
    cout << "NOW , ENTER SOME VALUES YOU WANT OF YOUR CHOICE \n";
    cout<<"----------------------------------------------- \n";
    for(i=0; i<10; i++)
    {
        cout << i+1 << ") ";
        cin >> a;
        tree.insert(a);
    }

    tree.print();
    bool result;
    cout << endl;
    cout<<"-------------------------------" << endl;
    cout<<"ENTER VALUES YOU WANT TO SEARCH\n";
    cout<<"-------------------------------" << endl;
    for(i=0; i<10; i++)
    {
        cout << endl << i+1 << ") ";
        cin>>search;
        result = tree.contains(search);
        cout << endl;
        if(result == true)
            cout<<"FOUND >> VALUE IS PRESENT IN THE TREE\n";
        else
            cout<<"NOT FOUND >> VALUE IS NOT PRESENT IN THE TREE\n";
    }
}
