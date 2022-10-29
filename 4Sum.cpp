// 18. 4Sum
// https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach will be to Sort the array and use 3 pointer + Binary Search to find all quaderplets and store them in Hashset to get unique quaderplets.
//  i =0 , j =i+1 , k+j+1 ;
// sum = i + j + k  and find (target - sum) in right half array using binary search .
// if found add in Hashset otherwise if not found do k++ .
// Time Complexity O(N^3 logN).

// Another Approch is to sort the array and take 2 for loops for 1 st two numbers and  and 2 pointer approach for other two.
// Time Complexity O(N^3) , Space Complexity O(1)
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;

    // If nums is empty return empty ans
    if (nums.size() == 0)
        return res;

    int n = nums.size();

    // Sort the array
    sort(nums.begin(), nums.end());

    // Traverse for 1st number
    for (int i = 0; i < n; i++)
    {
        // Traversee for 2 number
        for (int j = i+1; j < n; j++)
        {
            // take two pinter pointing to j+1 and n-1 index
            int front = j + 1, back = n - 1;
            // Calculate the newTarget by subtracting the ith and jth elements from initial target
            int newTarget = target - nums[i] - nums[j];

            // Two pointer approach
            while (front < back)
            {
                // if newTarget is smaller , increment front to find a greater number
                if ((nums[front] + nums[back]) < newTarget)
                    front++;
                // if newTarget is greater , decremment back to find a smaller number
                else if ((nums[front] + nums[back]) > newTarget)
                    back--;
                else
                {
                    // make a vector to push the 4 numbers
                    vector<int> quaderplets(4, 0);
                    quaderplets[0] = nums[i];
                    quaderplets[1] = nums[j];
                    quaderplets[2] = nums[front];
                    quaderplets[3] = nums[back];
                    res.push_back(quaderplets);

                    // Processing the duplicates of number 3
                    while (front < back && nums[front] == quaderplets[2])
                        ++front;
                    // Processing the duplicates of number 4
                    while (front < back && nums[back] == quaderplets[3])
                        --back;
                }
            }
            // Processing the duplicates of j (number 2)
            while (j + 1 < n && nums[j] == nums[j + 1])
                ++j;
        }
        // Processing the duplicates of i (number 1)
        while (i + 1 < n && nums[i] == nums[i + 1])
            ++i;
    }

    return res;
}

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);

    for (auto vec : res)
    {
        for (auto ele : vec)
            cout << ele << " ";
        cout << endl;
    }
    return 0;
}