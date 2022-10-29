// Subset Sum Problem
//

#include <bits/stdc++.h>
using namespace std;

// Approach - Recursion - TLE ❌
// Time - O( 2^N )

class Solution
{
public:
  bool isSubsetSumRecursive(int N, int arr[], int sum)
  {

    // base case
    if (N == 0 || sum == 0)
    {
      if (sum == 0)
        return 1;
      else
        return 0;
    }

    // if curr number is smaller or equal to sum
    //  we have 2 options either to include it in sum or not to include it
    if (arr[N - 1] <= sum)
    {
      return max(
          isSubsetSumRecursive(N - 1, arr, sum - arr[N - 1]),
          isSubsetSumRecursive(N - 1, arr, sum));
    }

    // else we have only 1 option to not include it
    else
      return isSubsetSumRecursive(N - 1, arr, sum);
  }

  // -----------------------------------------------------------------------------------------------------

  // Approach - 2️⃣ - Recursion + Memoization ✅
  // Time O(N*SUM) , Space O(N*M);

  int memo[102][10002];
  bool solve(int N, int arr[], int sum)
  {

    // base case
    if (N == 0 || sum == 0)
    {
      if (sum == 0)
        return 1;
      else
        return 0;
    }

    // if we have previously computed answer
    if (memo[N][sum] != -1)
      return memo[N][sum];

    // if curr number is smaller or equal to sum
    //  we have 2 options either to include it in sum or not to include it
    if (arr[N - 1] <= sum)
    {
      memo[N][sum] = max(
          solve(N - 1, arr, sum - arr[N - 1]),
          solve(N - 1, arr, sum));

      return memo[N][sum];
    }

    // else we have only 1 option to not include it
    else
      return memo[N][sum] = solve(N - 1, arr, sum);
  }

  bool isSubsetSumMemoized(int N, int arr[], int sum)
  {
    // intializing all values of memo table with -1
    memset(memo, -1, sizeof(memo));
    return solve(N, arr, sum);
  }

  // ---------------------------------------------------------------------------------------
  // Approach - 3️⃣ DP - Bottom Up🔥

  bool isSubsetSumBottomUp(int N, int arr[], int sum)
  {

    bool DP[102][10002];
    memset(DP, false, sizeof(DP));

    // If sum is 0 (first col), then answer is true , we can always create an empty subset.
    for (int i = 0; i <= N; i++)
      DP[i][0] = true;

    // If sum is not 0 and set is empty, then answer is always false
    for (int j = 1; j <= sum; j++)
      DP[0][j] = false;

    // filling DP in bottom up manner
    for (int i = 1; i <= N; i++)
    {
      for (int j = 1; j <= sum; j++)
      {
        // if curr elem is smaller or ewaul to sum
        // we have 2 option
        // either to include it or to exclude it
        if (arr[i - 1] <= j)
        {
          DP[i][j] = DP[i - 1][j] || DP[i - 1][j - arr[i - 1]];
        }
        // else we have only 1 option to exclude it
        else
          DP[i][j] = DP[i - 1][j];
      }
    }

    // answer at (N ,sum)
    return DP[N][sum];
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N, sum;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
    }
    cin >> sum;

    Solution ob;
    cout << ob.isSubsetSumRecursive(N, arr, sum) << endl;
    cout << ob.isSubsetSumMemoized(N, arr, sum) << endl;
    cout << ob.isSubsetSumBottomUp(N, arr, sum) << endl;
  }
  return 0;
}