#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Function to calculate the maximum subsequence sum using divide and conquer
int maxSubsequenceSum3(const vector<int>& nums, int left, int right)
{
    // cout << " START " << endl;
    if (left == right)
        return nums[left];

    int mid = (left + right) / 2;
    int maxLeftSum = maxSubsequenceSum3(nums, left, mid);
    int maxRightSum = maxSubsequenceSum3(nums, mid + 1, right);
    int maxLeftBorderSum = 0, leftBorderSum = 0;

    // Calculate the maximum subsequence sum on the left border
    for (int i = mid; i >= left; i--)
    {
        leftBorderSum += nums[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }

    int maxRightBorderSum = 0, rightBorderSum = 0;

    // Calculate the maximum subsequence sum on the right border
    for (int i = mid + 1; i <= right; i++)
    {
        rightBorderSum += nums[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }

    // Return the maximum of the left sum, right sum, and the sum crossing the border
    return max(max(maxLeftSum, maxRightSum), maxLeftBorderSum + maxRightBorderSum);
}

int main()
{
    using std :: chrono :: high_resolution_clock;
    using std :: chrono :: duration_cast;
    using std :: chrono :: duration;
    using std :: chrono :: milliseconds;
    // Set the seed for the random number generator
    srand(time(0));

    // Generate and store 1000 random numbers in a vector
    vector<int> nums;

    for (int i = 0; i < 500000; i++)
    {
        int randomNumber = (rand() % 100);
        nums.push_back(randomNumber);
    }

    // Call the maxSubsequenceSum3 function with the random number array and appropriate left and right indices
    int left = 0;
    int right = nums.size() - 1;

    auto time1 = high_resolution_clock :: now();
    int maxSUM = maxSubsequenceSum3(nums, left, right);
    auto time2 = high_resolution_clock :: now();


    auto  ms_int = duration_cast <milliseconds> (time2-time1);
    duration <double, std :: milli> ms_double = time2 - time1;

    cout << "MAXIMUM SUM : " << maxSUM << endl;
    cout << "TIME DIFFERENCE IN INTEGER : " << ms_int.count() << " MILLISECONDS" << endl;
    cout << "TIME DIFFERENCE IN DOUBLE : " << ms_double.count() << " MILLISECONDS" << endl;


    return 0;
}


