#include <bits/stdc++.h>
using namespace std;


/*  --------DP Solution-------------- 
    Time - O(n*sum) , Space O(n*sum)
    
    So we will create a 2D array of size (arr.size() + 1) * (target + 1) of type boolean. 
    The state DP[i][j] will be true if there exists a subset of elements from A[0….i] with sum value = ‘j’.

    if (A[i-1] > j)
        DP[i][j] = DP[i-1][j]
    This means that if current element has value greater than ‘current sum value’ we will copy the answer for previous cases
    
    else
        DP[i][j] = DP[i-1][j] OR DP[i-1][j-A[i-1]]
    And if the current sum value is greater than the ‘ith’ element we will see if any of previous states have already experienced the sum=’j’ OR any previous states experienced a value ‘j – A[i]’ which will solve our purpose.    
*/

// Returns true if there is a subset of set[]
// with sum equal to given sum
bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if
    // there is a subset of set[0..j-1] with sum
    // equal to i
    bool subset[n + 1][sum + 1];

    // If sum is 0, then answer is true , we can always create an empty subset.
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If sum is not 0 and set is empty, then answer is always false
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            // if number is greater than sum , we can't include it it our subset.
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];

            // if number is smaller than sum , we have two possiblity to inculde it or not to include it
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
        }
    }

    //  code to print table
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
            printf("%4d", subset[i][j]);
        cout << "\n";
    }

    return subset[n][sum];
}

int main()
{
    int set[] =  {1, 5,11, 5};
    int sum = 11;
    int n = sizeof(set) / sizeof(set[0]);

    cout << isSubsetSum(set, n, sum);

    return 0;
}