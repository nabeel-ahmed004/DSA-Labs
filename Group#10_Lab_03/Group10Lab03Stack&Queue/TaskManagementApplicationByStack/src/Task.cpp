#include "Task.h"

Task::Task()
{
    cout << endl << "\t\t___________________________________________________" << endl << endl;
    cout<<"\t\tWELCOME TO THE PROFESSIONAL TO-DO LIST APPLICATION!"<<endl;
    cout << "\t\t___________________________________________________" << endl << endl;
    front= NULL;
    rear=NULL;
    capacity=0;

}

Task::~Task()
{
    cout << "\t\tSEE YOU SOON!"<<endl;
}
bool Task::empty()
{
    if (capacity == 0)
        return true;
    return false;
}
void Task :: enTask(string temp)
{
    time_t now;

    struct tm nowLocal;

    now=time(NULL);

    nowLocal=*localtime(&now);

    nodetype newnode = new Node;
    newnode->array = temp;

    newnode->year=nowLocal.tm_year+1900;
    newnode->month=nowLocal.tm_mon+1;
    newnode->day=nowLocal.tm_mday;
    newnode->hour=nowLocal.tm_hour;
    newnode->minute=nowLocal.tm_min;
    newnode->second=nowLocal.tm_sec;

    newnode->next = NULL;

    if (!empty())
        rear->next = newnode;
    else
        front = newnode;

    rear = newnode;
    capacity++;

    cout << "\t\tTASK ADDED ON : " << newnode->day <<" / "<<newnode->month<<" / "<<newnode->year <<endl;
    cout << "\t\tTIME RIGHT NOW : " << newnode->hour <<" : "<<newnode->minute << " : "<<newnode->second << endl;
}

string Task::deTask()
{
    string temp;
    if (empty() == false )
    {
        temp=front->array;
        nodetype nextnode = front->next;
        delete front;
        front = nextnode;
        // Decrement the capacity
        capacity--;
    }
    else
    {
        cout<<"\t\tNO TASKS IN THE QUEUE!"<<endl;
        return temp;
    }
}
void Task::print()
{
    nodetype traverse = front;

    if (empty())
    {
        cout << "\t\tNO TASKS IN THE QUEUE!" << endl;
    }
    else
    {
        cout << endl << "\t\tHERE IS YOUR LIST OF TASKS!" << endl;


        for (int index = 0; index < capacity; index++)
        {
            cout << "\t\t________________________" << endl << endl;
            cout << "\t\tTASK # (" << index + 1 << ") >> " << traverse->array << endl;
            cout << "\t\tWAS, ADDED ON ," << endl;
            cout << "\t\tDATE : " << traverse->day <<" / "<< traverse->month<<" / "<< traverse->year << endl;
            cout << "\t\tTIME : " << traverse->hour <<" : "<< traverse->minute << " : " << traverse->second;
            cout << endl << "\t\t________________________" << endl << endl;
            traverse=traverse->next;
        }

    }
}
int Task::totalTasks()
{
    if (empty())
        return 0;
    return capacity;
}

void Task:: deleteTasks(Task * task)
{
    while (!empty())
        deTask();
}
/*
void Task:: postActiveTasks()
{

    //Am NOT APPLYING FILE HANDLING DUE TO SHORTAGE OF TIME & SESSIONALS

	fstream fout;

	fout.open("active tasks\\activeTasks.txt", ios::app);
	if (fout.is_open())
	{
	    int index = front;

	    do
        {
            fout << array[index] << endl;
            fout << day[rear] << endl;
            fout << month[rear] << endl;
            fout << year[rear] << endl;
            fout << hour[rear] << endl;
            fout << minute[rear] << endl;
            fout << second[rear];

            index = (index + 1) % capacity;
        } while (index != (rear + 1) % capacity);
	}
	else
	{
		cout << "FAILED TO OPEN FILE DUE TO SOME ERROR." << endl;
	}
}
*/
