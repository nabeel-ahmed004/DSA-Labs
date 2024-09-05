#include "BST.h"
#include<iostream>
using namespace std;

template class BST <int>;
template class BST <float>;
template class BST <double>;


template <class T>
BST<T> :: BST()
{
    //constructor
}
template <class T>
BST<T> :: ~BST()
{
    //destructor
}
template <class T>
bool BST<T> :: empty() const
{
    if(root == NULL)
    {
        return true;
    }
    else
        return false;
}
template <class T>
void BST<T> :: print()
{
    print(root);
}
template <class T>
void BST<T> ::print(Node*& t)
{

    if(t != NULL)
    {
        print(t->left);
        string message = to_string(t->element);
        int width = message.length() + 4;
        string line(width, '-');
        cout << line << endl;
        cout << "| " << setw(width - 4) << left << message << " |" << endl;
        print(t->right);
    }
}
template <class T>
bool BST<T> :: contains(const T x)
{
    return contains(x, root);
}
template <class T>
void BST<T> :: insert(const T x)
{
    insert(x, root);
}
template <class T>
void BST<T> :: remove(const T x)
{
    remove(x, root);
}
template <class T>
void BST<T> :: insert(const T x, Node*& t) const
{
    if (t == NULL)
    {
        t = new Node;
        t->element=x;
        t->left=NULL;
        t->right=NULL;
    }
    else if (x<t->element)
        insert(x,t->left);
    else if (t->element<x)
        insert(x,t->right);
}
template <class T>
void BST<T> :: remove(const T x, Node*& t)
{
    if (t==NULL)
        return;
    if (x<t->element)
        remove(x,t->left);
    else if (t->element < x)
        remove (x, t->right);
    else if (t->left != NULL && t->right != NULL)
    {
        t->element = findMin(t->right)->element;
        remove(t->element,t->right);
    }
    else
    {
        Node* oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
    }
}
template <class T>
typename BST <T> :: Node* BST<T> :: findMin(Node* t)
{
    if(t == NULL)
    {
        return NULL;
    }
    if(t->left == NULL)
    {
        return t;
    }
    return findMin(t->left);
}
template <class T>
void BST<T> :: makeEmpty(Node*& t) {}
template <class T>
bool BST<T> :: contains(const T x, Node* t) const
{
    if(t == NULL)
        return false;
    else if(x < t->element)
        return contains(x, t->left);
    else if(x > t->element)
        return contains(x, t->right);
    else
        return true;
}
