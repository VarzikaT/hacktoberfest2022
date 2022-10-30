// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/

#include <bits/stdc++.h>
using namespace std;

// Approach - 1️⃣ - Using Nested ofr loops to generate every subarray and check for Sum equal to K ❌ TLE
// Time O(N^3) ,Space O(1)

// Approach 2️⃣ - Using Prefix Sum ❌ TLE
// Time O(N^2) , Space O(1)
int subarraySum(vector<int> &nums, int K)
{
    int n = nums.size();

    vector<int> PrefixSum(n);

    PrefixSum[0] = nums[0];

    // calculating prefix sum
    for (int i = 1; i < n; i++)
        PrefixSum[i] = PrefixSum[i - 1] + nums[i];

    int count = 0;

    // itertaing for all subarray
    for (int i = 0; i < n; i++)
    {
        // for subarrays staring from first index
        if (PrefixSum[i] == K)
            count++;

        // for other subarrays
        for (int j = i + 1; j < n; j++)
        {
            if ((PrefixSum[j] - PrefixSum[i]) == K)
                count++;
        }
    }

    return count;
}

// Approach 3️⃣- Using HashMap and Prefix Sum
// Time O(N) , Space O(N)

int subarraySumHashMap(vector<int> &nums, int k)
{
    int curr_Sum = 0;
    int count = 0;

    // Unordered_map to store frequency of Sum.
    unordered_map<int, int> mp;

    // put zero with frequency 1 in the map
    mp[0] = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        // Update the currentSum (PrefixSum)
        curr_Sum += nums[i];

        // If map contains (currentSum - k) then we have found our subarray with sum equal to k .
        if (mp.find(curr_Sum - k) != mp.end())
        {
            count += mp.at(curr_Sum - k);
        }

        // If it does not contain that number simply add it to the map .
        mp[curr_Sum]++;
    }
    return count;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << subarraySum(nums, 3) << endl;
    cout << subarraySumHashMap(nums, 3);
    return 0;
}
