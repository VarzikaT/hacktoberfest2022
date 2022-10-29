// 198. House Robber
// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

// Approach - DP

int rob(vector<int> &nums)
{
  int n = nums.size();

  if (n == 1)
    return nums[0];

  vector<int> dp(n, 0);

  // intialization of staring points.
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);

  for (int i = 2; i < n; i++)
  {
    // amount robbed at index i will be max of amount robbed till index i-1 and amount that can be robbed at index i (which is amount robbed at index i-2 + amount in nums at index i)
    dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
  }

  return dp[n - 1];
}

int main()
{
  vector<int> nums = {1, 2, 3, 1};

  cout << rob(nums);
  return 0;
}