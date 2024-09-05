#include "Stack.h"
#include<iostream>
using namespace std;

Stack::Stack(int size = 10)
{
    values = new double[size];
    top = -1;
    maxTop = size - 1;
}
void Stack::push(const double x)
{
    if (full()) // if stack is full, print error
        cout << "Error: the stack is full." << endl;
    else
        values[++top] = x;
}
double Stack::pop()
{
    if (empty())
    {   //if stack is empty, print error
        cout << "Error: the stack is empty." << endl;
        return -1;
    }
    else
        return values[top--];
}
double Stack::top()
{
    if (empty())
    {
        cout << "Error: the stack is empty." << endl;
        return -1;
    }
    else
        return values[top];
}
void Stack::print() const
{
    cout << "top -->";
    for (int i = top; i >= 0; i--)
        cout << "\t|\t" << values[i] << "\t|" << endl;
    cout << "\t|---------------|" << endl;
}
