// 0 - 1 Knapsack Problem
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1#

#include <bits/stdc++.h>
using namespace std;

/*  Approach - Recursion + Memoization
    Time - O(N*M)  Space - O(N*M)
*/

class Solution
{
private:
  int maxProfit(int wt[], int val[], int capacity, int size, int t[][1001])
  {
    // base condition .
    if (capacity == 0 || size == 0)
      return 0;

    // if our matrix has value at t[size],[capacity] return that , need not to do any recursive calls for that.
    if (t[size][capacity] != -1)
      return t[size][capacity];

    // If weight is smaller or equal to the capacity of knapsack
    if (wt[size - 1] <= capacity)
    {
      // return max of both if we include the weight or we dont include it .
      return t[size][capacity] = max(val[size - 1] + maxProfit(wt, val, capacity - wt[size - 1], size - 1, t),
                                     maxProfit(wt, val, capacity, size - 1, t));
    }
    // weight is more than capacity so we skip that weight.
    else
      return t[size][capacity] = maxProfit(wt, val, capacity, size - 1, t);
  }

public:
  // Function to return max value that can be put in knapsack of capacity W.
  int knapSack(int W, int wt[], int val[], int n)
  {
    // table to store the results for further use if required
    int memo[1001][1001];
    // intializaing all values of table to -1
    memset(memo, -1, sizeof(memo));

    return maxProfit(wt, val, W, n, memo);
  }
};

//  Driver Code Starts.
int main()
{
  // taking total testcases
  int t;
  cin >> t;
  while (t--)
  {
    // reading number of elements and weight
    int n, w;
    cin >> n >> w;

    int val[n];
    int wt[n];

    // inserting the values
    for (int i = 0; i < n; i++)
      cin >> val[i];

    // inserting the weights
    for (int i = 0; i < n; i++)
      cin >> wt[i];
    Solution ob;
    // calling method knapSack()
    cout << ob.knapSack(w, wt, val, n) << endl;
  }
  return 0;
}