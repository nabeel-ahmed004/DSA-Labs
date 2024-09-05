#include <iostream>
#include <list>
#include <algorithm>
#include <hashing.h>

using namespace std;

struct student_info
{
    string name;
    int age;
    int rollNumber;
    string residency;
    void get_data()
    {
        cout << "\nEnter the name:";
        cin >> name;
        cout << "\nEnter the age:";
        cin >> age;
        cout << "\nEnter the roll number:";
        cin >> rollNumber;
        cout << "\nEnter the place of residence:";
        cin >> residency;
    }
};

// sort the list in ascending order according to roll number of students
bool sort_List(const student_info &first, const student_info &second)
{
    return (first.rollNumber < second.rollNumber);
}

int main()
{
    cout << "Lab Task 1\n\n";
    list<student_info> list_students; // make a list of type student_info
    student_info student1, student2, student3, student4; // make objects of type student_info
    // populate objects
    cout << "Enter the data for the first student\n";
    student1.get_data();
    cout << "\nEnter the data for the second student\n";
    student2.get_data();
    cout << "\nEnter the data for the third student\n";
    student3.get_data();
    cout << "\nEnter the data for the fourth student\n";
    student4.get_data();
    cout << "\n-----------------------------\n";

    // insert objects into the list
    list_students.push_back(student1);
    list_students.push_back(student2);
    list_students.push_back(student3);
    list_students.push_back(student4);

    int i=1;
    // display output in unsorted order
    cout << "Before sorting, the list is\n";
    for(list<student_info>::iterator it = list_students.begin(); it != list_students.end(); it++)
    {
        cout << "\nInformation of student# " << i <<endl;
        cout << "Name: " << (it)->name << "\nAge: " << (it)->age;
        cout << "\nRoll Number " << (it)->rollNumber << "\nResidence: " << (it)->residency << endl;
        i++;
    }
    cout << "\n-----------------------------\n";
    list_students.sort(sort_List);

    i=1;
    // display output in sorted order
    cout << "After sorting according to roll numbers, the list is\n";
    for(list<student_info>::iterator it = list_students.begin(); it != list_students.end(); it++)
    {
        cout << "\nInformation of student# " << i <<endl;
        cout << "Name: " << (it)->name << "\nAge: " << (it)->age;
        cout << "\nRoll Number " << (it)->rollNumber << "\nResidence: " << (it)->residency << endl;
        i++;
    }
    cout << "\n-----------------------------\n";



    cout << "\nLab Task 2\n";
    int n = 9;
    i=0;
    string a[n];
    cout << "Enter string values to insert in table\n";
    for(i=0; i<n; i++)
        cin >> a[i]; //initialize the array of strings
    hashing h(9); // make an object using parameterized character
    for (i = 0; i < n; i++)
        h.insertItem(a[i]); //one by one insert all the values into the hashing table
    h.displayHash(); // display the Hash table
}
