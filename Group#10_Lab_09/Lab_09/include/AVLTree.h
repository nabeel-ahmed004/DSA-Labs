#ifndef AVLTREE_H
#define AVLTREE_H

template <typename T>
class AVLTree
{
public:
    // Constructors and destructor
    AVLTree();
    AVLTree(const AVLTree& a);
    ~AVLTree();

    // Public member functions
    bool empty() const;
    bool search(const T x);
    void insert(const T x);
    void remove(const T x);
    void printTree() const;

private:
    // Node structure representing
    // individual elements in the AVL tree
    struct Node
    {
        T element;
        Node* left;
        Node* right;
        Node* parent;

        // Constructor for Node
        Node(const T& value)
        {
            element = value;
            left = nullptr;
            right = nullptr;
            parent = nullptr;
        }
    };

    // Private data members
    Node* root;

    // Private member functions
    int height(Node* t) const;
    Node* copyTree(const Node* t);
    Node* findMin(Node* t);
    void deleteTree(Node* t);
    bool search(const T x, Node* t) const;
    void insert(const T x, Node*& t);
    void remove(const T x, Node*& t);
    void singleLeftRotation(Node*& k2);
    void singleRightRotation(Node*& k2);
    void doubleLeftRotation(Node*& k3);
    void doubleRightRotation(Node*& k3);
    void balance(Node*& t);
    void print(Node* t) const;
};

#endif // AVLTREE_H
