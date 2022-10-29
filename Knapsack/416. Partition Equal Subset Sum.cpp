// 416. Partition Equal Subset Sum
// https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

// Following are the two main steps to solve this problem:
// 1) Calculate sum of the array. If sum is odd, there can not be two subsets with equal sum, so return false.
// 2) If sum of array elements is even, calculate sum/2 and find a subset of array with sum equal to sum/2.

// Approach 1️⃣ - We can use Recursion or Recursion + Memoization for Step 2
// Time - O(2^N)

// Approach 2️⃣ 🔥 Dynamic Programming
// Time O(N* sum/2) , Space O(N*sum/2)

/*  --------DP Solution--------------
    Time - O(n*sum) , Space O(n*sum)

    So we will create a 2D array of size (arr.size() + 1) * (target + 1) of type boolean.
    The state DP[i][j] will be true if there exists a subset of elements from A[0….i] with sum value = ‘j’.

    if (A[i-1] > j)
        DP[i][j] = DP[i-1][j]
    This means that if current element has value greater than ‘current sum value’ we will copy the answer for       previous cases

    else
        DP[i][j] = DP[i-1][j] OR DP[i-1][j-A[i-1]]
        And if the current sum value is greater than the ‘ith’ element we will see if any of previous states            have already experienced the sum=’j’ OR any previous states experienced a value ‘j – A[i]’ which will           solve our purpose.
*/
bool isSubsetSum(vector<int> nums, int target)
{
  int n = nums.size();

  // The value of matrix[i][j] will be true if there is a subset of nums[0..j-1] with sum equal to i
  vector<vector<bool>> matrix(n + 1, vector<bool>(target + 1));

  // If sum is not 0 and set is empty, then answer is always false
  for (int j = 1; j < target + 1; j++)
    matrix[0][j] = false;

  // If sum is 0, then answer is true , we can always create an empty subset.
  for (int i = 0; i < n + 1; i++)
    matrix[i][0] = true;

  // Filling our table.
  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < target + 1; j++)
    {
      // if number is greater than target sum , we can't include it it our subset.
      if (nums[i - 1] > j)
        matrix[i][j] = matrix[i - 1][j];
      // if number is smaller than sum , we have two possiblity to inculde it or not to include it
      else
        matrix[i][j] = matrix[i - 1][j] || matrix[i - 1][j - nums[i - 1]];
    }
  }

  return matrix[n][target];
}

bool canPartition(vector<int> &nums)
{

  int n = nums.size();

  int total_sum = 0;

  // getting total_sum of all elemnts
  for (int num : nums)
    total_sum += num;

  // if total_sum is even then only we can make equal partition.
  if (total_sum % 2 == 0)
    return isSubsetSum(nums, total_sum / 2);

  // if total_sum is odd return false.
  else
    return false;
}

int main()
{
  vector<int> nums = {1, 5, 11, 5};
  cout << canPartition(nums);
  return 0;
}