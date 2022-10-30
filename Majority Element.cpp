// 169. Majority Element
// https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>
using namespace std;

// 1 - Brute Force Approach will be to check occurance for each element by iterating through array .
// Time Complexity O(N^2)

// 2 - Another Approach will be to maintain a Frequency Array .
// Time Complexity O(N) if using Array & Time Complexity O(N log N) if using map
// (if you use unordered map , it takes O(1) for searching but takes O(N) if there are collisions so overall it would be O(N^2)).

// 3 - ANother Approach will be to sort the array
//  and the majority element will be at mid in sorted array as it exist more than n/2 times
//  Time - O(NlogN) , Space O(1)

/*
 3 - Moore's Voting Algorithm
Basic idea of the algorithm is if we cancel out each occurrence of an element e,
with all the other elements that are different from e then e will exist till end if it is a majority element

    majority element exist (n/2 + 1) times therefore
    other elements => n - (n/2 + 1) = n- n/2 - 1
                   => n/2 -1
    therefore there will be only one majority elements that exist more than n/2 times
*/

int majorityElement(vector<int> &nums)
{

    int count = 0;
    int majority_till_now = 0;

    for (int curr : nums)
    {
        // If the count reaches 0 then update the potential majority element to the current element and set count to 1.
        if (count == 0)
            majority_till_now = curr;

        // If next element is same then increments the count, otherwise decrement
        if (curr == majority_till_now)
            count++;

        else
            count--;
    }

    return majority_till_now;
}

int main()
{

    vector<int> nums = {-2, -2, 1, 1, 1, -2, -2};
    cout << majorityElement(nums);
    return 0;
}