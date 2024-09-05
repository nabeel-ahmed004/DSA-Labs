#include "hashing.h"

//parameterized constructor
hashing :: hashing(int value)
{
    this->capacity = value; // set capacity of the hash table
    table = new list<string>[capacity]; // create a new array of list type to represent the hashing table
}

// inserts a key into hash table
void hashing :: insertItem(string key_string)
{
    int index = hashFunction(key_string);//calculate hash function
    table[index].push_back(key_string); // insert string into the table
}

// hash function to map values to key
int hashing :: hashFunction(string x)
{
    int n = x.size(); // calculate the size of the string
    long long sum = -1*x[0]; // initializing in this way to cancel the extra sum for index 0
    for(int i=0;i<n;i++)
        sum+= pow(31,i)*x[i]; //calculating the sum of each index value of string
    return (sum % capacity); // return table index of value to be inserted
}

// function to display hash table
void hashing::displayHash()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << i; // display the index
        for (auto it : table[i])
            cout << " --> " << it; // display the string
        cout << endl;
    }
}
