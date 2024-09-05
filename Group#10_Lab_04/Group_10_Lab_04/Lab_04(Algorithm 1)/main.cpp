#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>

using namespace std;

int calc_maxSum() {
    /* Simulating a long operation
    std::this_thread::sleep_for(150ms);*/
    using namespace std::chrono_literals;

    int maxSum = 0, thisSum;
    int i, j, k;
    int size = 3000;
    int a[size];
    for(i=0; i< size; i++)
    {
        a[i] = rand()%100;
    }

    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            thisSum = 0;
            for(k=0; k<size; k++)
            {
                thisSum = thisSum + a[k];
            }
            if(thisSum > maxSum)
            {

                maxSum = thisSum;
            }
        }
    }
    return maxSum;
}

int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    auto t1 = high_resolution_clock::now();
    int maxSum = calc_maxSum();
    auto t2 = high_resolution_clock::now();

    // Getting duration as milliseconds (integer)
    auto ms_int = duration_cast<milliseconds>(t2 - t1);

    // Getting duration as milliseconds (double)
    duration<double, std::milli> ms_double = t2 - t1;

    cout<<"Maximum Sum= "<<maxSum<<endl;
    std::cout << ms_int.count() << "ms\n";
    std::cout << ms_double.count() <<"ms\n";

    return 0;
}
