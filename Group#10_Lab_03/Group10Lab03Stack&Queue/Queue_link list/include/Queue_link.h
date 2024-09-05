#ifndef QUEUE_LINK_H
#define QUEUE_LINK_H

// Node structure for the linked list
struct Node {
    double data;     // Data of the node
    Node* next;      // Pointer to the next node
};
typedef Node* nodetype; // Typedef for a pointer to Node, named nodetype

class Queue_link {
public:
    // Constructor
    Queue_link();

    // Copy Constructor
    Queue_link(Queue_link& queue);

    // Destructor
    ~Queue_link();

    // Check if the queue is empty
    bool empty();

    // Enqueue a new element into the queue
    void enqueue(double x);

    // Dequeue an element from the front of the queue
    double dequeue();

    // Print the elements in the queue
    void print(void);

protected:

private:
    nodetype front; // Pointer to the front of the queue
    nodetype rear;  // Pointer to the rear of the queue
    int count;      // Number of elements in the queue
};

#endif // QUEUE_LINK_H
