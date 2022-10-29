// 740. Delete and Earn
// https://leetcode.com/problems/delete-and-earn/

#include <bits/stdc++.h>
using namespace std;

//  Approach 1️⃣ - Recursion ❌ TLE
int recursive(vector<int> &nums, int i, int n)
{
  // base case
  if (i >= n)
    return 0;

  // curr element
  int currVal = nums[i];

  // initial curr sum
  int currSum = nums[i];

  // index to take elements (from i +1)
  int idx = i + 1;

  // taking all occurances of currVal and addding it to our currSum
  while (idx < n && nums[idx] == currVal)
  {
    currSum += currVal;
    idx++;
  }

  // skipping all occurances of elements having value equal to currVal + 1
  while (idx < n && nums[idx] == currVal + 1)
    idx++;

  // we have two choices
  //  whether to include the sum of this current element in our answer
  //  or not include the sum of current element in our answer
  // so we explore both the possibilities

  // If we decide to take the curr element in our answer, then upto the element we skip the next value, we paas that index
  int include = currSum + recursive(nums, idx, n);

  // but if decided not to make this current element then simply paas i + 1
  int notInclude = recursive(nums, i + 1, n);

  return max(include, notInclude);
}

// Approach 2️⃣ - Recursion + Memoization ✅
int memoized(vector<int> &nums, int i, int n, vector<int> &dp)
{
  // base case
  if (i >= n)
    return 0;

  // if we have previously calculated answer for this
  if (dp[i] != -1)
    return dp[i];

  // curr element
  int currVal = nums[i];

  // initial curr sum
  int currSum = nums[i];

  // index to take elements (from i +1)
  int idx = i + 1;

  // taking all occurances of currVal and addding it to our currSum
  while (idx < n && nums[idx] == currVal)
  {
    currSum += currVal;
    idx++;
  }

  // skipping all occurances of elements having value equal to currVal + 1
  while (idx < n && nums[idx] == currVal + 1)
    idx++;

  // we have two choices
  //  whether to include the sum of this current element in our answer
  //  or not include the sum of current element in our answer
  // so we explore both the possibilities

  // If we decide to take the curr element in our answer, then upto the element we skip the next value, we paas that index
  int include = currSum + memoized(nums, idx, n, dp);

  // but if decided not to make this current element then simply paas i + 1
  int notInclude = memoized(nums, i + 1, n, dp);

  return dp[i] = max(include, notInclude);
}

int deleteAndEarn(vector<int> &nums)
{

  int n = nums.size();

  // dp vector
  vector<int> dp(n + 1, -1);

  sort(nums.begin(), nums.end());
  return memoized(nums, 0, n, dp);
}

int deleteAndEarn(vector<int> &nums)
{

  sort(nums.begin(), nums.end());
  int n = nums.size();
  return recursive(nums, 0, n);
}
int main()
{
  return 0;
}