#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void bubbleSort(int a[], int size)
{
    int i, j, temp;
    for(i=0; i<size-1; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(a[j+1] < a[j])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void insertionSort(int a[], int size)
{
    int i, j, temp;
    for(i=1; i<size; i++)
    {
        temp = a[i];
        for(j=i; j>0 && temp<a[j-1]; j--)
        {
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}

void merge(int a[], int left, int middle, int right)
    {
        int n1 = middle - left + 1;
        int n2 = right - middle;
        int i, j, k;
        int L[n1], R[n2];

        for (i = 0; i < n1; i++) {
            L[i] = a[left + i];
        }
        for (j = 0; j < n2; j++) {
            R[j] = a[middle + 1 + j];
        }

        i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                a[k] = L[i];
                i++;
            } else {
                a[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            a[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            a[k] = R[j];
            j++;
            k++;
        }
}

void mergeSort(int a[], int left, int right) {
    if (left < right)
        {
            int middle = left + (right - left) / 2;

            mergeSort(a, left, middle);
            mergeSort(a, middle + 1, right);

            merge(a, left, middle, right);
        }
}

int partition(int a[], int left, int right) {
    int pivot = a[right];
    int i = (left - 1);

    for (int j = left; j <= right - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return (i + 1);
}

void quickSort(int a[], int left, int right) {
    if (left < right) {
        int pivot = partition(a, left, right);

        quickSort(a, left, pivot - 1);
        quickSort(a, pivot + 1, right);
    }
}

int main()
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    int i, size = 100, a[size], b[size], c[size], d[size];

    for(i=0; i<size; i++)
    {
        a[i] = rand()%100;
        b[i] = a[i];
        c[i] = a[i];
        d[i] = a[i];
    }

    //Time calculation for Bubble Sort Algorithm
    auto t1 = high_resolution_clock::now();
    bubbleSort(a, size);
    auto t2 = high_resolution_clock::now();

    // Getting duration as milliseconds (integer)
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    // Getting duration as milliseconds (double)
    duration<double, std::milli> ms_double = t2 - t1;

    cout <<"Time for bubble sort in integer form= "<<ms_int.count() << "ms\n";
    cout <<"Time for bubble sort in double form= "<< ms_double.count() <<"ms\n\n";

    //Time calculation for Insertion Sort Algorithm
    t1 = high_resolution_clock::now();
    insertionSort(b, size);
    t2 = high_resolution_clock::now();

    // Getting duration as milliseconds (integer)
    ms_int = duration_cast<milliseconds>(t2 - t1);

    // Getting duration as milliseconds (double)
    ms_double = t2 - t1;

    cout <<"Time for insertion sort in integer form= "<<ms_int.count() << "ms\n";
    cout <<"Time for insertion sort in double form= "<< ms_double.count() <<"ms\n\n";

    //Time calculation for Merge Sort Algorithm
    t1 = high_resolution_clock::now();
    mergeSort(c, 0, size-1);
    t2 = high_resolution_clock::now();

    // Getting duration as milliseconds (integer)
    ms_int = duration_cast<milliseconds>(t2 - t1);

    // Getting duration as milliseconds (double)
    ms_double = t2 - t1;

    cout <<"Time for merge sort in integer form= "<<ms_int.count() << "ms\n";
    cout <<"Time for merge sort in double form= "<< ms_double.count() <<"ms\n\n";

    //Time calculation for Quick Sort Algorithm
    t1 = high_resolution_clock::now();
    quickSort(d, 0, size-1);
    t2 = high_resolution_clock::now();

    // Getting duration as milliseconds (integer)
    ms_int = duration_cast<milliseconds>(t2 - t1);

    // Getting duration as milliseconds (double)
    ms_double = t2 - t1;

    cout <<"Time for quick sort in integer form= "<<ms_int.count() << "ms\n";
    cout <<"Time for quick sort in double form= "<< ms_double.count() <<"ms\n";
}
