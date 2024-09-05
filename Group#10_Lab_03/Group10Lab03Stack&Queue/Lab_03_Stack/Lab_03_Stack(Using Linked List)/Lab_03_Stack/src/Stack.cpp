#include "Stack.h"
#include<iostream>
using namespace std;

Stack::Stack()
{
    topi = NULL;
}
Stack::Stack(const Stack& stack)
{
    if(stack.topi == NULL)
    {
        cout<<"The stack is empty\n";
    }
    topi = NULL;
    Node* temp = stack.topi;

    while(temp!=NULL)
    {
        Node *newNode = new Node;
        newNode->data= temp->data;

        if(topi == NULL)
        {
            topi = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode -> next = topi;
            topi = newNode;
        }
        temp = temp->next;
    }
}
Stack::~Stack()
{

}
bool Stack::empty() const
{
    if(topi == NULL)
        return true;
    else
        return false;
}
void Stack::push(const double x)
{
    Node *temp = topi;
    Node *newNode = new Node;
    newNode->data = x;
    if(topi == NULL)
    {
        topi = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode -> next = temp;
        topi = newNode;
    }
}
double Stack::pop()
{
    if(topi == NULL)
    {
        cout<<"The stack is empty\n";
    }
    else
    {
        Node *temp = topi;
        topi = topi->next;
        delete temp;
    }
}
double Stack::top() const
{
    if(topi == NULL)
    {
        cout<<"The stack is empty";
    }
    else
        return topi->data;
}
void Stack::print() const
{
    Node *temp = topi;
    cout << "top -->";
    while(temp!=NULL)
    {
        cout << "\t|\t" << temp->data << "\t|" << endl;
        temp=temp->next;
    }
    cout << "\t|---------------|" << endl;
}
