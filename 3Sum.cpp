// 15. 3Sum
// https://leetcode.com/problems/3sum/

// Brute Force Approach would be to use 3 for loops to test out each possisble triplet and put it in set data structure for eliminating duplicate values. Time Complexity - O(N^3 log m) - log m is time taken to insert triplet in set data structure ( m is the size of set ) .

// Two Pointer approach - sort the array , 
// we have to find out (a + b + c = 0) ==> (b+ c) = -a  
// Time Complexity - O(N^2) 


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{   
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    // If size is less than 3 , no triplets can be formed , return empty ans
    if(nums.size() < 3)
        return ans;

    // This loop moves for finding a
    for (int i = 0; i < nums.size() - 2; i++)
    {
        // This check is to neglect(avoid) the duplicates.
        // If its first element or its the element which is not equal to its previous element ( not duplicates ) .
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {

            // low is for b , high is for c
            int low = i + 1, high = nums.size() - 1;
            // this is equivalent to -a
            int sum = 0 - nums[i];

            // Getting triplet for a particular value of i.
            while (low < high)
            {

                // if ( b + c = - a ) push_back triplet
                if (nums[low] + nums[high] == sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);

                    //push_back the triplet
                    ans.push_back(temp);

                    // Ignoring the duplicates for low and high . moving them until a non_duplicate is found.
                    while (low < high && nums[low] == nums[low + 1])
                        low++;
                    while (low < high && nums[high] == nums[high - 1])
                        high--;

                    low++, high--;
                }

                // If desired sum is lesser than required sum we increment low as the array is sorted and we have to increase the sum .
                else if (nums[low] + nums[high] < sum)
                    low++;

                // If desired sum is greater than required sum we decrement high as the array is sorted and we have to decrease the sum .
                else
                    high--;
            }
        }
    }
    return ans;
}

int main()
{

    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> ans = threeSum(nums);

    for(auto each : ans){
        for(auto i : each)  {
            cout << i <<" ";
        }
    }

    return 0;
}