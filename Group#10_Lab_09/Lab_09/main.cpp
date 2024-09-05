#include <iostream>
#include "AVLTree.h"
#include <set>
using namespace std;

int main()
{
    cout << endl << " ";
    // Declaration of variables
    int i;
    AVLTree <double> tree;
    int a, search_element, j = 1;

    set<int> insertedElements; // Store the inserted elements uniquely

    // Generate and insert random numbers into the AVL tree
    for (int i = 0; i < 100; i++)
    {
        int a;
        do {
            a = (rand() % 900) + 100;
        } while (insertedElements.count(a) > 0); // Check if the element already exists in the set
        cout << a << " ";
        tree.insert(a);
        insertedElements.insert(a);
        if ((i + 1) % 10 == 0)
            cout << endl << " ";
    }
    cout << endl << " >> RANDOMLY GENERATED NUMBERS HAVE BEEN INSERTED IN AVL TREE" << endl << endl << " ";

    // Print the AVL tree
    tree.printTree();
    cout << " -------------------------------------- \n";
    cout << " NOW , ENTER SOME VALUES OF YOUR CHOICE \n";
    cout << " -------------------------------------- \n";

    // Insert values entered by the user into the AVL tree
    for (i = 0; i < 10; i++)
    {
        cout <<" "<< i + 1 << ") ";
        cin >> a;
        tree.insert(a);
    }
    cout << endl << endl << " ";

    // Print the AVL tree after user-inserted values
    tree.printTree();
    bool result;
    cout << endl;
    cout << " -------------------------------" << endl;
    cout << " ENTER VALUES YOU WANT TO SEARCH\n";
    cout << " -------------------------------" << endl;

    // Search for values entered by the user in the AVL tree
    for (i = 0; i < 10; i++)
    {
        cout << endl
             << " " << i + 1 << ") ";
        cin >> search_element;
        result = tree.search(search_element);
        cout << endl;
        if (result == true)
            cout << " FOUND >> VALUE IS PRESENT IN THE TREE\n";
        else
            cout << " NOT FOUND >> VALUE IS NOT PRESENT IN THE TREE\n";
    }

    return 0;
}
