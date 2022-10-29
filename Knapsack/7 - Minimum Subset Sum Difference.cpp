// Minimum Subset Sum Difference

#include <bits/stdc++.h>
using namespace std;

// this is a variation problem of SubsetSum 
/*
    we have to divide the array into two subsets such that there absolute diff is minimum.
    s1 and s2 be our two subsets then s1 + s2 = totalSum(range);
    and we have to minimize s2 - s1.

    we can say that s2 = range - s1 ;

    therefore s2 - s1 ==> range - s1 - s1 ==>  range - 2*s1 

    therefore in order to minimize (s2 -s1) ,  s1 can take values from 0 to range/2.

    but s1 can take only those values which can be formed by the subsets from the array given.

    so we will find the possible values for s1 with subset sum of range/2 , we have done this in previous problem subsetSum;
    (the last row of table gives the values which can be formed by the array elements ).

    when we will have values of s1 we will simple iterate over the array and find out the minimum diff of (s2 - s1)
    minDiff = min(minDiff , range - 2*( possible values of s1))

*/
// this function will calculate the possible SubsetSums we can make in range of 0 to targetSum
vector<int> isSubsetSum(vector<int> &nums, int targetSum)
{
    int n = nums.size();

    bool subset[n + 1][targetSum + 1];

    // If targetSum is 0, then answer is true , we can always create an empty subset.(first column)
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // If targetSum is not 0 and nums is empty, then answer is always false boz we dont have any element .(first row , except [0][0])
    for (int i = 1; i <= targetSum; i++)
        subset[0][i] = false;

    // Fill the subset table in bottom up manner
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= targetSum; j++)
        {
            // if number is greater than targetSum , we can't include it it our subset.
            if (j < nums[i - 1])
                subset[i][j] = subset[i - 1][j];

            // if number is smaller than targetSum , we have two possiblity to exclude it or to include it
            if (j >= nums[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - nums[i - 1]];
        }
    }


    vector<int> ans;

    // storing the possible values s1 can have.
    for (int j = 0; j < targetSum + 1; j++)
    {
        if (subset[n][j] == true)
            ans.push_back(j);
    }
    
    return ans;
}

int minimumDifference(vector<int> &nums)
{

    int range = 0;

    for (int i = 0; i < nums.size(); i++)
        range += nums[i];

    vector<int> S1 = isSubsetSum(nums, range / 2);

    // minSum to store the minDiff of s2 - s1
    int minSum = INT_MAX;

    // calculate minSum .
    for (int i  = 0; i < S1.size(); i++)
    {
        int first = S1[i];
        int second = range - S1[i];

        minSum = min(minSum, abs(first - second));
    }

    return minSum;
}

int main()
{
    vector<int> nums = {3, 9, 7, 3};

    cout << minimumDifference(nums);

    return 0;
}
