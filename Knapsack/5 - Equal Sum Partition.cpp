#include <bits/stdc++.h>
using namespace std;

/*
    The first key point is that the total_sum of all elements should be even , then only we can make equal partition.

    after this check we have to find subset whose sum is half of total_sum of array.
    now this problem becomes similar to Subsest sum problem in which we have to find a subset having sum equal to the target.
*/
// a helper function which will help us to check if we can make a subset with given target sum or not.
bool isSubsetSum(vector<int> &nums, int target)
{
    int n = nums.size();

    int subsetSum[n + 1][target + 1];

    // If target sum is 0, then answer is true ,bcoz we can always create an empty subset.
    // filling the 1st column in subsetSum matrix (first column reprents 0 target sum).
    for (int i = 0; i <= n; i++)
        subsetSum[i][0] = true;

    // If sum is not 0 and we have 0 elements (i.e. array is empty), then answer is always false
    // filling the 1st row in subsetSum matrix (first row represents 0 elements ).
    for (int i = 1; i <= target; i++)
        subsetSum[0][i] = false;

    // Fill the subsetSum table in bottom up manner
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            // if number is smaller than target_sum , we have two possiblity to inculde it or not to include it
            if (nums[i] <= j)
            {
                subsetSum[i][j] = subsetSum[i][j - nums[i - 1]] || subsetSum[i - 1][j];
            }
            // if number is greater than target_sum , we can't include it it our subset.
            else
            {
                subsetSum[i][j] = subsetSum[i - 1][j];
            }
        }
    }

    //  code to print table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
            printf("%4d", subsetSum[i][j]);
        cout << "\n";
    }
    // our ans will be at position (n,target) , if we can make a subset will target_sum or not
    return subsetSum[n][target];
}
bool EqualSum(vector<int> &nums)
{
    int n = nums.size();
    int total_sum = 0;

    // getting total_sum of all elemnts
    for (int num : nums)
        total_sum += num;

    // if total_sum is even then only we can make equal partition.
    if (total_sum % 2 == 0)
    {
        return isSubsetSum(nums, total_sum / 2);
    }
    // if total_sum is odd return false.
    else
        return false;
}

int main()
{
    vector<int> nums = {1, 11, 5, 5};
    cout << EqualSum(nums);
    return 0;
}