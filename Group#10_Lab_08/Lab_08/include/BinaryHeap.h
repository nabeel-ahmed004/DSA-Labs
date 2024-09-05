#ifndef BINARYHEAP_H
#define BINARYHEAP_H
#include <iostream>
#include <vector>

using namespace std;

template <typename Comparable>
class BinaryHeap
{
    public:
        BinaryHeap(int capacity=100);
        explicit BinaryHeap(const vector<Comparable> &items);
        bool isEmpty() const;
        void insert(const Comparable &x);
        void deleteMin();
        void deleteMin(Comparable &minItem);
        void makeEmpty();
        vector<Comparable> GetSorted();
    private:
        int currentSize;//number of elements in heap
        vector<Comparable> array;//the heap array
        void buildHeap();
        void percolateDown(int hole);
};

#endif // BINARYHEAP_H
