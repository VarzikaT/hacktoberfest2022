// 494. Target Sum
//

#include <bits/stdc++.h>
using namespace std;

/*
    Approach - Recursion - Brute force .
    We need to try to put both the + and - symbols at every location in the given nums array and find out the assignments which lead to the required result S.

    We always append a + sign and a - sign both to the element at the current index and calls itself with the updated sum as sum + nums[i]  and sum - nums[i] respectively along with the updated current index as i+1. Whenever we reach the end of the array, we compare the sum obtained with SS. If they are equal, we increment the countcount value to be returned.

    Time - O(2^N)  Space - O(N)


    Other Method - This Question is similar to count of Subset with Given Diff , here sum is equal to diff only

    🅾 Explanation -  if we assign + or - sign before numbers , they eventually become two subsets one containing all -ve elememnts and other all posiitves and if we add those two subsets we get the diff between them.

*/

void calculate(vector<int> &nums, int i, int sum, int S, vector<int> &ans)
{
  if (i == nums.size())
  {
    if (sum == S)
    {
      ans[0] += 1;
    }
  }
  else
  {
    calculate(nums, i + 1, sum + nums[i], S, ans);
    calculate(nums, i + 1, sum - nums[i], S, ans);
  }
}

// Approach - Dynamic Programming 🔥✅
// Intution - if we assign + or - sign before numbers , they eventually become two subsets one containing all -ve elememnts and other all posiitves and if we find diff b/w them that is our answer target.

// Similar to Count of Subset Sum with given Diff - ❗❗❗❕❕❕
//  nums : [0,0,0,0,0,0,0,0,1], target = 1.
// The solution doesn't consider presence of "0"s in the array. Why the output is different ?
// Because, if we have "0", then, it can have +0 and -0 and still will not effect the sum of a set.
// For example: Target value is = 2
// 1) {0,2} = {+0,2}, {-0,2}.  Ans: 2
// But if we increase number of 0s,
// 2) {0,0,2} = {+0,+0,2}, {+0,-0,2}, {-0,+0,2},{-0,-0,2} . Ans: 4

// ❗❕ So, if you observe, your answer increase by (2^number of 0s) i.e. pow(2,number of zeros).

// other cases we need to handle is:
// if(target < total_Sum || (total_Sum + target )% 2 != 0)

// same code of count of subset with given sum
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
      // in case of 0 the sum is not affected thats why we are adding this case to the case where element can't be added
      if (set[i - 1] > j || set[i - 1] == 0)
      {
        table[i][j] = table[i - 1][j];
      }
      else
      {
        table[i][j] = table[i - 1][j] + table[i - 1][j - set[i - 1]];
      }
    }
  }

  return table[n][sum];
}

// code of count subsets with given diff
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

int findTargetSumWays(vector<int> &nums, int target)
{

  int totalSum = 0;
  int zeroes = 0;

  // getting totalsum and no of zeroes
  for (auto &i : nums)
  {
    totalSum += i;
    if (i == 0)
      zeroes++;
  }

  // edge cases we need to handle
  if (target > totalSum || target < 0 || (totalSum + target) % 2 != 0)
    return 0;

  // multiplying our ans with 2^no of zeroes
  return pow(2, zeroes) * countSubsetsWithDifference(nums, target);
}

int main()
{
  vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 1};
  int target = 1;

  cout << findTargetSumWays(nums, target);

  return 0;
}