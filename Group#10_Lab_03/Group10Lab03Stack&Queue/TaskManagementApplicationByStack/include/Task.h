#ifndef TASK_H
#define TASK_H


#include <iostream>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

struct Node {

    string array;

    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;    // Data of the node

    Node* next;      // Pointer to the next node
};


typedef Node* nodetype;

class Task
{
    public:
        Task();
        virtual ~Task();
        bool empty();
        void enTask (string temp);
        string top();
        void print();
        string deTask();
        int totalTasks();
        void deleteTasks(Task * task);
        // void postActiveTasks();

    protected:

    private:

        nodetype front; // Pointer to the front of the queue
        nodetype rear;  // Pointer to the rear of the queue
        int capacity;


};

#endif // TASK_H
