#include "AVLTree.h"
#include <iostream>

// Explicit instantiation of the AVLTree class template for the type double
template class AVLTree<double>;

// Constructor: Initializes an empty AVL tree
template <typename T>
AVLTree<T>::AVLTree()
{
    root = nullptr;
}

// Copy constructor: Creates a new AVL tree by copying an existing tree
template <typename T>
AVLTree<T>::AVLTree(const AVLTree& a)
{
    root = nullptr;
    root = copyTree(a.root);
}

// Destructor: Frees the memory occupied by the AVL tree
template <typename T>
AVLTree<T>::~AVLTree()
{
    deleteTree(root);
}

// Recursive function to copy a tree
template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::copyTree(const Node* t)
{
    if (t == nullptr)
        return nullptr;

    Node* newNode = new Node(t->element);
    newNode->left = copyTree(t->left);
    newNode->right = copyTree(t->right);

    return newNode;
}

// Recursive function to delete a tree
template <typename T>
void AVLTree<T>::deleteTree(Node* t)
{
    if (t != nullptr)
    {
        deleteTree(t->left);
        deleteTree(t->right);
        delete t;
    }
}

// Check if the AVL tree is empty
template <typename T>
bool AVLTree<T>::empty() const
{
    return (root == nullptr);
}

// Public wrapper function for searching a value in the AVL tree
template <typename T>
bool AVLTree<T>::search(const T x)
{
    return search(x, root);
}

// Public wrapper function for inserting a value into the AVL tree
template <typename T>
void AVLTree<T>::insert(const T x)
{
    insert(x, root);
}

// Public wrapper function for removing a value from the AVL tree
template <typename T>
void AVLTree<T>::remove(const T x)
{
    remove(x, root);
}

// Recursive function to calculate the height of a node in the AVL tree
template <typename T>
int AVLTree<T>::height(Node* t) const
{
    return (t == nullptr) ? -1 : 1 + std::max(height(t->left), height(t->right));
}

// Recursive function to insert a value into the AVL tree and perform balancing
template <typename T>
void AVLTree<T>::insert(const T x, Node*& t)
{
    if (t == nullptr)
        t = new Node(x);
    else if (x < t->element)
        insert(x, t->left);
    else if (x > t->element)
        insert(x, t->right);

    // Perform balancing
    balance(t);
}

// Recursive function to search for a value in the AVL tree
template <typename T>
bool AVLTree<T>::search(const T x, Node* t) const
{
    if (t == nullptr)
        return false;
    else if (x == t->element)
        return true;
    else if (x < t->element)
        return search(x, t->left);
    else
        return search(x, t->right);
}

// Recursive function to remove a value from the AVL tree and perform balancing
template <typename T>
void AVLTree<T>::remove(const T x, Node*& t)
{
    if (t == nullptr)
        return;

    if (x < t->element)
        remove(x, t->left);
    else if (x > t->element)
        remove(x, t->right);
    else
    {
        if (t->left != nullptr && t->right != nullptr)
        {
            // Node with two children: Get the in-order successor
            Node* successor = findMin(t->right);
            t->element = successor->element;
            remove(successor->element, t->right);
        }
        else
        {
            // Node with one child or no child
            Node* temp = t;
            t = (t->left != nullptr) ? t->left : t->right;
            if (t != nullptr)
            {
                t->parent = temp->parent;
            }
            delete temp;
        }
    }
    // Perform balancing
    balance(t);
}

// Recursive function to calculate the balance factor and perform rotations
template <typename T>
void AVLTree<T>::balance(Node*& t)
{
    if (t == nullptr)
        return;

    int balanceFactor = height(t->left) - height(t->right);

    // Left Heavy
    if (balanceFactor > 1)
    {
        if (height(t->left->left) >= height(t->left->right))
            singleLeftRotation(t);
        else
            doubleLeftRotation(t);
    }
    // Right Heavy
    else if (balanceFactor < -1)
    {
        if (height(t->right->right) >= height(t->right->left))
            singleRightRotation(t);
        else
            doubleRightRotation(t);
    }
}

// Perform a single left rotation
template <typename T>
void AVLTree<T>::singleLeftRotation(Node*& k2)
{
    Node* k1 = k2->left;
    k2->left = k1->right;
    if (k1->right != nullptr)
        k1->right->parent = k2;

    k1->right = k2;
    k1->parent = k2->parent;
    k2->parent = k1;

    k2 = k1;
}

// Perform a single right rotation
template <typename T>
void AVLTree<T>::singleRightRotation(Node*& k2)
{
    Node* k1 = k2->right;
    k2->right = k1->left;
    if (k1->left != nullptr)
        k1->left->parent = k2;

    k1->left = k2;
    k1->parent = k2->parent;
    k2->parent = k1;

    k2 = k1;
}

// Perform a double left-right rotation
template <typename T>
void AVLTree<T>::doubleLeftRotation(Node*& k3)
{
    singleRightRotation(k3->left);
    singleLeftRotation(k3);
}

// Perform a double right-left rotation
template <typename T>
void AVLTree<T>::doubleRightRotation(Node*& k3)
{
    singleLeftRotation(k3->right);
    singleRightRotation(k3);
}

// Public wrapper function to print the AVL tree
template <typename T>
void AVLTree<T>::printTree() const
{
    print(root);
    std::cout << std::endl;
}

// Recursive function to print the AVL tree in an in-order traversal
template <typename T>
void AVLTree<T>::print(Node* t) const
{
    static int k = 1;
    if (t != nullptr)
    {
        print(t->left);
        std::cout << t->element;
        (k++ % 10 == 0) ? std::cout << "\n " : std::cout << " ";
        print(t->right);
    }
}

// Function to find the node with the minimum value in a subtree
template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::findMin(Node* t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    else
        return findMin(t->left);
}
