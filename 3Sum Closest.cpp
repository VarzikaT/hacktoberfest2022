// 16. 3Sum Closest
// https://leetcode.com/problems/3sum-closest/

// Two Pointer Approach - Sort the array and For every i of nums array traverse the other indexes for desired closest sum. Time Complexity - O(N^2)

#include <bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> &nums, int target)
{
    // Intialize answer
    int ans = nums[0] + nums[1] + nums[2];

    // Sort the nums vector
    sort(nums.begin(), nums.end());

    // n-2 Since we have taken n-1 in our pointer so no need to go beyond that
    for (auto i = 0; i < nums.size() - 2; i++)
    {
        // for each value of i check the vector for closest sum
        // take two pointer left and right , make a left pointing next to i and a right pointer at the last element of the vector
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            // Calculate current sum
            int current_Sum = nums[i] + nums[left] + nums[right];

            // calculate thr absolute value of ans - target and currentSum - target , whichever is minimum , update the answer
            if (abs(current_Sum - target) < abs(ans - target))
                ans = current_Sum;

            // if our current sum is greater than out target decrement right for a smaller value
            if (current_Sum > target)
                right--;
            // if our current sum is smaller than out target increment left for a greater value
            else if (current_Sum < target)
                left++;
            else
                return ans;
        }
    }

    return ans;
}

int main()
{

    vector<int> nums = {-1, -2, 1, -4};
    int target = 1;
    cout << threeSumClosest(nums, target);

    return 0;
}