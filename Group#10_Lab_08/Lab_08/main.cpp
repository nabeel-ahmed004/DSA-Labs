#include "BinaryHeap.h"
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main()
{
    using chrono::high_resolution_clock;
    using chrono::duration_cast;
    using chrono::duration;
    using chrono::milliseconds;


    BinaryHeap<int> myHeap;
    int i;
    long int size = 20;
    vector<int> a;
    //print the array before sorting
    cout<<"Unsorted vector:"<<endl;
    for(i=0;i <size;i ++)
    {
        a.push_back(rand()%10000+1);
        myHeap.insert(a[i]);
        cout<<a[i]<<" ";
    }
    cout<<endl<<"--------------------------------"<<endl;

    auto t1 = high_resolution_clock::now();
    vector<int> sortedVector = myHeap.GetSorted();
    auto t2 = high_resolution_clock::now();

    BinaryHeap<int> newHeap(a);
    vector<int> newSortedVector = newHeap.GetSorted();
    size_t j;
    //print the array after sorting
    cout<<"Sorted vector:"<<endl;
    for(j=1; j<newSortedVector.size(); ++j)
        cout<<newSortedVector[j]<<" ";
    cout<<endl<<"--------------------------------"<<endl;

    int minimumElement;
    while(!newHeap.isEmpty()) //delete all elements until the tree is empty
    {
        newHeap.deleteMin(minimumElement);
        cout<<"Deleting current minimum element: "<<minimumElement<<endl; //display the minimum element being deleted
    }
    cout<<endl<<"--------------------------------"<<endl;


    // Getting duration as milliseconds (integer)
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    // Getting duration as milliseconds (double)
    duration<double, std::milli> ms_double = t2 - t1;

    cout << "Time for sorting Binary Heap of size = "<<size<< " in int format: " << ms_int.count() << "ms\n";
    cout << "Time for sorting Binary Heap of size = "<<size<< " in double format: " << ms_double.count() <<"ms\n";

    return 0;
}
