#ifndef STACK_H
#define STACK_H


class Stack {
    public:
        Stack(int size = 10);// constructor
        ~Stack() { delete [] values; }// destructor
        bool empty() { return top == -1; } //see if the stack is empty or not
        void push(const double x); //add the top element of stack
        double pop(); //remove the first element of stack
        bool full() { return top == maxTop; }
        double top(); //return the top value of the stack
        void print(); //print the stack
    private:
        int maxTop;// max stack size = size -1
        int top;// current top value of stack
        double* values;// an element of array
};

#endif // STACK_H
