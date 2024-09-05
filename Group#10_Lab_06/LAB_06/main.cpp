#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

// Getting time from the Operating System :))

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


                                // QUICK SORT ALGORITHM 2

int partition(int arr[], int low, int high)
{
    int randomIndex = low + rand() % (high - low + 1);
    swap(arr[randomIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void QuickSort2(int a[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(a, low, high);
        QuickSort2(a, low, pivot - 1);
        QuickSort2(a, pivot + 1, high);
    }
}

                                // QUICK SORT ALGORITHM 1


void swaping(int arr[],int x,int y)
{
    int temp=arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}
int median(int arr[],int l,int r)
{
    int mid = (l+r)/2;
    if(arr[mid]<arr[l])
        swaping(arr,l,mid);
    if(arr[r]<arr[l])
        swaping(arr,l,r);
    if(arr[r]<arr[mid])
        swaping(arr,r,mid);
    swaping(arr,mid,r - 1);
    return arr[r-1];
}
//Quick sort algorithm
void QuickSort1(int arr[],int left,int right)
{
    if(left+10<right)
    {
        int pivot = median(arr,left,right);
        int i=left,j=right-1;
        while(i<=j)
        {
            while(arr[++i]<pivot){}
            while(pivot<arr[--j]){}
            if(i<j)
                swaping(arr,i,j);
            else
                break;

        }
        swaping(arr,i,right-1);
        QuickSort1(arr,left,i-1);
        QuickSort1(arr,i+1,right);
    }
    else {
        // Use a different sorting algorithm (e.g., insertion sort) for small subarrays
        for(int i=left+1;i<=right;++i)
        {
            int key=arr[i];
            int j=i-1;
            while(j>=left && arr[j]>key)
            {
                arr[j+1]=arr[j];
                --j;
            }

            arr[j+1]=key;
}
}
}                                // RADIX SORT ALGORITHM


int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{

    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void RadixSort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);

}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
        cout << endl;
}

int main()
{
    int size=100000,i;

    int quickalgo1[size];
    int quickalgo2[size];
    int radixalgo[size];

    srand (time(0));

    for(i=0;i<size;i++)
    {
        quickalgo1[i]=rand()%1000;
        quickalgo2[i]=quickalgo1[i];
        radixalgo[i]=quickalgo2[i];
    }
    cout << endl;
    cout << "TIME FOR QUICK SORT ALGORITHM 1" << endl << endl;
    auto t1 = high_resolution_clock::now();
    QuickSort1(quickalgo1,0,size-1);
    auto t2 = high_resolution_clock::now();
    auto ms_int_algo1 = duration_cast<milliseconds>(t2 - t1);
    duration<double, std::milli> ms_double_algo1 = t2-t1;
    std::cout<<"TIME IN INTEGER FORM : "<< ms_int_algo1.count() << "ms\n";
    std::cout <<"TIME IN DOUBLE FORM : "<< ms_double_algo1.count() << "ms\n" <<endl;
    // print(quickalgo1, size);

    cout << "TIME FOR QUICK SORT ALGORITHM 2" << endl << endl;
    auto t3 = high_resolution_clock::now();
    QuickSort2(quickalgo2, 0, size-1);
    auto t4 = high_resolution_clock::now();
    auto ms_int_algo2 = duration_cast<milliseconds>(t4 - t3);
    duration<double, std::milli> ms_double_algo2 = t4 - t3;
    cout <<"TIME IN INTEGER FORM : "<<ms_int_algo2.count() << "ms\n";
    cout <<"TIME IN DOUBLE FORM : "<< ms_double_algo2.count() <<"ms\n\n";
    // print(quickalgo2, size);

    cout << "TIME FOR RADIX SORT ALGORITHM" << endl << endl;
    auto t5 = high_resolution_clock::now();
    RadixSort(radixalgo, size);
    auto t6 = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(t6 - t5);
    duration<double, std::milli> ms_double = t6 - t5;
    cout <<"TIME IN INTEGER FORM : "<<ms_int.count() << "ms\n";
    cout <<"TIME IN DOUBLE FORM : "<< ms_double.count() <<"ms\n\n";
    // print(radixalgo, size);

    return 0;
}
