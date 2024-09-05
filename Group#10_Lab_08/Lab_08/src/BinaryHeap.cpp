#include "BinaryHeap.h"
using namespace std;

template <class Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capacity)
{
    currentSize = 0;
    array.resize(capacity+1);
}

template <class Comparable>
BinaryHeap<Comparable>::BinaryHeap(const vector<Comparable> &items)
{
    currentSize = items.size();
    array.resize(items.size() + 1);
    for(int i=0; i<items.size();i++)
    {
        array[i+1] = items[i]; //copy vector elements into a new vector
    }
    buildHeap();
}

template <class Comparable>
bool BinaryHeap<Comparable>::isEmpty() const
{
    return currentSize == 0; //return true if vector is empty
}

template <class Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &x)
{
    if(array.size()-1 == currentSize) //resize the array if resizing is required
        array.resize((array.size()*2));
    //upwards percolation
    int hole = ++currentSize;
    for(; hole>1 && x<array[hole/2]; hole/=2) //move hole to correct position
    {
        array[hole] = array[hole/2];
    }
    array[hole] = x;
}

template <class Comparable>
void BinaryHeap<Comparable>::deleteMin()
{
    if(isEmpty()) //check if heap is empty or not
        cout<<"Heap is empty\n";
    array[1] = array[currentSize--];
    percolateDown(1);
}

template <class Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable &minItem)
{
    if(isEmpty()) //check if heap is empty or not
        cout<<"Heap is empty\n";
    minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
}

template <class Comparable>
vector<Comparable> BinaryHeap<Comparable>::GetSorted()
{
    // Create a copy of the original heap
    BinaryHeap<Comparable> copyHeap(array);

    vector<Comparable> sortedVector;
    while (!copyHeap.isEmpty())
    {
        Comparable minimumItem;
        copyHeap.deleteMin(minimumItem); //delete minimum element
        sortedVector.push_back(minimumItem); //add the element in a vector to sort the original vector
    }

    return sortedVector; //return the sorted vector
}

template <class Comparable>
void BinaryHeap<Comparable>::makeEmpty()
{
    currentSize = 0;//setting currentsize to 0
}

template <class Comparable>
void BinaryHeap<Comparable>::buildHeap()
{
    for(int i=currentSize/2;i>0;i--)
        percolateDown(i); //calling a function for percolating downwards
}

template <class Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole)
{
    int childIndex;
    Comparable temporary = array[hole];

    // loop while there are valid children for the current hole
    for(; hole*2<=currentSize; hole = childIndex)
    {
        childIndex = hole*2; // calculate the index of the left child

         // check if there is a right child and if it is smaller than the left child
        if(childIndex!=currentSize && (array[childIndex+1] < array[childIndex]))
            childIndex++;

        // check if the value of the child is smaller than the temporary value
        if(array[childIndex]<temporary)
            array[hole] = array[childIndex]; // move the child up to the hole
        else
            break;
    }
    array[hole] = temporary; // place the temporary value into its final position
}
