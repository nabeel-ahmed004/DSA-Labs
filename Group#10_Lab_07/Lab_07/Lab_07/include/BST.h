#ifndef BST_H
#define BST_H

#include <iostream>
#include <iomanip>

template <typename T>
class BST
{
    public:
        BST();
        BST(const BST& t);
        ~BST();
        bool empty() const;
        bool contains(const T x);
        bool search(const T x); // contains
        void insert(const T x); // compose x into a tree
        void remove(const T x); // decompose x from a tree
        void print();
    private:
        struct Node
        {
            T element;
            Node* left;
            Node* right;
           /* Node(double y, Node* l, Node* r)
            {
                element = y;
                left = l;
                right = r;
            } */ // constructor for Node
        };
        Node* root=NULL;
        void print(Node*& t);
        void insert(const T x, Node*& t) const; // recursive function
        void remove(const T x, Node*& t);
        Node* findMin(Node* t);
        void makeEmpty(Node*& t); // recursive ‘destructor’
        bool contains(const T x, Node* t) const;
};

#endif // BST_H
