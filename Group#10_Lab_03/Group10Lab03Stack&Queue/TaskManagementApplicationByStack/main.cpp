#include "Task.h"

int main() {
    Task taskManager;  // Creating an instance of the Task class

    while (true) {

        cout << "\n\t\tCHOOSE AN OPTION:" << endl;
        cout << "\t\t1. ADD A TASK" << endl;
        cout << "\t\t2. REMOVE 1ST TASK, IF DONE" << endl;
        cout << "\t\t3. DELETE ALL TASKS" << endl;
        cout << "\t\t4. PRINT TASK LIST" << endl;
        cout << "\t\t5. NUMBER OF TASKS LEFT" << endl;  // Added option
        cout << "\t\t6. EXIT" << endl;

        int choice;
        cout << "\t\tENTER YOUR CHOICE (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string newTask;
                cout << "\t\tENTER THE TASK TO ADD: ";
                cin.ignore();  // Ignore any previous newline character
                getline(cin, newTask);
                taskManager.enTask(newTask);
                // taskManager.postActiveTasks();
                break;
            }
            case 2: {
                string removedTask = taskManager.deTask();
                if (removedTask != "-1") {
                    cout << "\t\t1ST TASK REMOVED: " << removedTask << endl;
                }
                break;
            }
            case 3: {
                taskManager.deleteTasks(&taskManager);  // Deleting all tasks
                cout << "\t\tALL TASKS DELETED." << endl;
                break;
            }
            case 4:
                taskManager.print();
                break;
            case 5:
                cout << "\t\tNUMBER OF TASKS IN LIST: " << taskManager.totalTasks() << endl;
                break;
            case 6:
                taskManager.deleteTasks(&taskManager);  // Deleting allocated memory
                cout << "\t\tEXITING APPLICATION. GOODBYE!" << endl;
                return 0;
            default:
                cout << "\t\tINVALID CHOICE. PLEASE ENTER A NUMBER BETWEEN 1 AND 6." << endl;
        }
    }

    return 0;
}
