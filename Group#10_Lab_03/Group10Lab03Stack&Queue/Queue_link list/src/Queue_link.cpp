#include "Queue_link.h"

#include <iostream>
using namespace std;

// Constructor
Queue_link::Queue_link()
{
    front = NULL;
    rear = NULL;
    count = 0;
    // Constructor
}

// Destructor
Queue_link::~Queue_link()
{
    double val;
    // Deallocate memory for each node until the queue is empty
    while (!empty())
        dequeue();
}

// Copy Constructor
Queue_link::Queue_link(Queue_link& queue)
{
    front = NULL;
    rear = NULL;
    count = 0;
    nodetype cur = queue.front;
    // Copy each node from the source queue to the current queue
    while (cur != NULL)
    {
        enqueue(cur->data);
        cur = cur->next;
    }
}

// Check if the queue is empty
bool Queue_link::empty()
{
    return (count == 0);
}

// Enqueue a new element into the queue
void Queue_link::enqueue(double x)
{
    nodetype newnode = new Node;
    newnode->data = x;
    newnode->next = NULL;

    // If the queue is empty, set both front and rear to the new node
    if (empty())
    {
        front = newnode;
    }
    else
    {
        // Otherwise, link the current rear to the new node
        rear->next = newnode;
    }
    // Update the rear to the new node and increment the count
    rear = newnode;
    count++;
}

// Dequeue an element from the front of the queue
double Queue_link::dequeue()
{
    double val;
    if (empty())
    {
        cout << "Error: the queue is empty" << endl;
    }
    else
    {
        // Retrieve the value from the front node
        val = front->data;
        // Move to the next node and deallocate the memory of the front node
        nodetype nextnode = front->next;
        delete front;
        front = nextnode;
        // Decrement the count
        count--;
    }
    return val;
}

// Print the elements in the queue
void Queue_link::print(void)
{
    cout << "front -->";
    nodetype cur = front;

    for (int i = 0; i < count; i++)
    {
        if (i == 0)
            cout << "\t";
        else
            cout << "\t\t";
        cout << cur->data;
        if (i != count - 1)
            cout << endl;
        else
            cout << "\t<-- rear" << endl;
        cur = cur->next;
    }
}
