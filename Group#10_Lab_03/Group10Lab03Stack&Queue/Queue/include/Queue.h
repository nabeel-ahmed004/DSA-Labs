#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

class Queue
{
public:
    // Default constructor
    Queue();

    // Parameterized constructor
    Queue(int size);

    // Copy constructor
    Queue(Queue& queue);

    // Destructor
    ~Queue();

    // Check if the queue is empty
    bool empty();

    // Enqueue a new element into the queue
    void enqueue(double x);

    // Dequeue an element from the front of the queue
    double dequeue();

    // Check if the queue is full
    bool full();

    // Print the elements in the queue
    void print(void);

private:
    int front;     // Index of the front element
    int rear;      // Index of the rear element
    int count;     // Number of elements in the queue
    int maxsize;   // Maximum size of the queue
    double* que;   // Array to store queue elements
};

#endif // QUEUE_H
