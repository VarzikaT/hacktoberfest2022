//  Count the number of subset with a given difference

#include <bits/stdc++.h>
using namespace std;

// Approach - Dynamic Programming 🔥✅
//  Suppose Two Subsets S1 and S2
//  S1 + S2 = TotalSum
//  S1 - S2 = Diff (given)
//  S1 = Diff + S2  ==> S1 = Diff + TotalSum - S1 ==> 2S1 = Diff + TotalSum
//  ==> S1 = (Diff + TotalSum) / 2

// So at last we need to find count of subsets with sum equal to (Diff + TotalSum)/2

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

    return table[n][sum];
}

int countSubsetsWithDifference(vector<int> &nums, int diff)
{
    int total_sum = 0;

    for (int num : nums)
        total_sum += num;

    // S1 + S2 = TotalSum
    // S1 - S2 = Diff
    // S1 = Diff + S2  ==> S1 = Diff + TotalSum - S1 ==> 2S1 = Diff + TotalSum
    // ==> S1 = (Diff + TotalSum) / 2

    int newSum = (diff + total_sum) / 2;

    return countSubsetsWithSum(nums, newSum);
}

int main()
{
    vector<int> nums = {1, 1, 1, 1 , 1};
    int diff = 3;
    cout << countSubsetsWithDifference(nums, diff);
    return 0;
}