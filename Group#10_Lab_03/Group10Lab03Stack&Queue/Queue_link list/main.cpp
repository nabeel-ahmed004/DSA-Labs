#include <iostream>
#include "Queue_link.h"

using namespace std;

int main(void)
{
    Queue_link queue;

    cout << "Enqueue 5 items." << endl;
    for (int x = 0; x < 5; x++)
        queue.enqueue(x);

    cout << "Now attempting to enqueue again..." << endl;
    queue.enqueue(5);

    queue.print();

    double value;
    value = queue.dequeue();
    cout << "Retrieved element = " << value << endl;

    queue.print();

    queue.enqueue(7);
    queue.print();

    return 0;
}

