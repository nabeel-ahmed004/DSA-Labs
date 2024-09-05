#include "Queue.h"

// Default constructor
Queue::Queue()
{

}

// Parameterized constructor
Queue::Queue(int size)
{
    que = new double[size];
    count = 0;
    maxsize = 100;
    front = 0;
    rear = -1;
    // Constructor
}

// Destructor
Queue::~Queue()
{
    // Destructor
    delete que;
}

// Copy Constructor
Queue::Queue(Queue& queue)
{
    que = new double[100];
    // Copy elements from the source queue to the current queue
    for (int i = 0; i < count; i++)
        que[i] = queue.que[i];
}

// Check if the queue is empty
bool Queue::empty()
{
    return (count == 0);
}

// Check if the queue is full
bool Queue::full()
{
    if (count < maxsize)
        return false;
    else
        return true;
}

// Enqueue a new element into the queue
void Queue::enqueue(double x)
{
    if (full())
        cout << "Error: the queue is full." << endl;
    else
    {
        rear = (rear + 1) % maxsize;
        que[rear] = x;
        count++;
    }
}

// Dequeue an element from the front of the queue
double Queue::dequeue()
{
    int x;
    if (empty())
        cout << "Error: the queue is empty." << endl;
    else
    {
        x = que[front];
        front = (front + 1) % maxsize;
        count--;
    }
    return x;
}

// Print the elements in the queue
void Queue::print(void)
{
    cout << "front -->";
    for (int i = 0; i < count; i++)
    {
        if (i == 0)
            cout << "\t";
        else
            cout << "\t\t";
        cout << que[(front + i) % maxsize];
        if (i != count - 1)
            cout << endl;
        else
            cout << "\t<-- rear" << endl;
    }
}
