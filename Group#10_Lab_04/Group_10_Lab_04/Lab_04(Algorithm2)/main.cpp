#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int improved_algo(const int a[], const int size){
    int maxSum = 0;

    for (int i=0; i< size; i++) {
    int thisSum =0;
    for (int j = i; j < size; j++) {

    thisSum += a[j];
    if(thisSum > maxSum)
    maxSum = thisSum;

}
}

return maxSum;
}

int main() {

    int size= 500;
    int a[size];
    // Measuring time.
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    srand (time(0));
    for(int i=0;i<size;i++)
    {
        a[i] = rand()%100 ;
    }
    auto t1 = high_resolution_clock::now();

    cout<<"Maximum Sum = "<<improved_algo(a, size)<<endl;

    auto t2 = high_resolution_clock::now();

    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    duration<double, std::milli> ms_double = t2-t1;

    // Getting number of milliseconds as an integer.
    std::cout << "ms_int.count(): " << ms_int.count() << "ms\n";

    // Getting number of milliseconds as a double.
    std::cout << "ms_double.count(): " << ms_double.count() << "ms\n";

    return 0;
}
