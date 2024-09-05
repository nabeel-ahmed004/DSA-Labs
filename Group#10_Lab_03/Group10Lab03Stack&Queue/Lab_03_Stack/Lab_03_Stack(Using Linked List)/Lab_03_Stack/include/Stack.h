#ifndef STACK_H
#define STACK_H


struct Node{
    public:
        double data;
        Node* next;
};

class Stack {
    public:
        Stack(); // constructor
        Stack(const Stack& stack); // copy constructor
        ~Stack(); // destructor
        bool empty() const;
        void push(const double x); //get the top data value of stack
        double pop(); // change the stack by adding a data value
        double top() const; // keep the stack unchanged
        void print() const;

    private:
        Node *topi;
};
#endif // STACK_H
