#ifndef HASHING_H
#define HASHING_H

#include <iostream>
#include <list>
#include <math.h>

using namespace std;

class hashing
{
    public:
        // Constructor
        hashing(int value);
        // inserts a key into hash table
        void insertItem(string x);
        // deletes a key from hash table
        //void deleteItem(string key);
        // hash function to map values to key
        int hashFunction(string x);
        // display hash table
        void displayHash();
    private:
        int capacity; // number of buckets or the size of hash table
        // pointer to an array containing buckets
        list<string> *table;
};

#endif // HASHING_H
