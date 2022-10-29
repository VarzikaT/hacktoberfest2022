//  Count of Subsets Sum with a Given Sum

#include <bits/stdc++.h>
using namespace std;

// Approach 1️⃣ Recursion TLE ❌
int subsetSum(vector<int> arr, int n, int i, int sum, int count)
{

    // if we have generated all the subsets , check sum
    // instead of this (i == n) base case ,
    // base case should be if(i == n || sum == 0)
    // if sum has become 0 we dont need to make further recursive calls for it
    if (i == n)
    {
        if (sum == 0)
        {
            count++;
        }
        return count;
    }
    
    if (arr[i] <= sum)
    {

        // if we include the number
        int count1 = subsetSum(arr, n, i + 1, sum - arr[i], count);

        // if we dont include the number
        int count2 = subsetSum(arr, n, i + 1, sum, count);

        // returning the sum of both
        return count1 + count2;
    }

    return subsetSum(arr, n, i + 1, sum, count);
}

// Approach 3️⃣  DP 🔥
int countSubsetsWithSum(vector<int> &set, int sum)
{
    int n = set.size();

    int table[n + 1][sum + 1];

    // if sum is 0 we can always make an empty subset of sum 0
    for (int i = 0; i < n + 1; i++)
        table[i][0] = 1;

    // if we dont have any element we cannot make any sum other than empty (Zero sum) , that's why j is iterating from 1 to sum + 1
    for (int j = 1; j < sum + 1; j++)
        table[0][j] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            // if current number is smaller or equal to sum
            // we have two choices, exlcude it or inlcude it in our subset
            if (set[i - 1] <= j)
            {
                table[i][j] = table[i - 1][j] + table[i - 1][j - set[i - 1]];
            }
            // else we have to exclude it
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    // //  code to print table
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= sum; j++)
    //         printf("%4d", table[i][j]);
    //     cout << "\n";
    // }

    return table[n][sum];
}

int main()
{
    vector<int> nums = {2, 3, 1, 4, 5, 6, 8, 10};
    cout << subsetSum(nums, nums.size(), 0, 10, 0);
    cout << countSubsetsWithSum(nums, 10);
    return 0;
}