// 496. Next Greater Element I
// https://leetcode.com/problems/next-greater-element-i/

#include <bits/stdc++.h>
using namespace std;

//  Approach - Brute Force
//  Use nested for loops to traverse throught the array ans find the next graeter element .
// Time O(N^2) , Space O(1);

// Approach - Using Stack
// Use a stack and traverse from right side of array and for every number in nums check for the greater number in stack and if there is smaller number present on top of stack pop out number until you find a greater element and if stack becomes empty simple put -1 for that number
// Time O(N) , Space O(N);

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

  int size = nums2.size();

  stack<int> s;
  vector<int> ans;

  for (int i = size - 1; i >= 0; i--)
  {
    // if stack is empty
    if (s.size() == 0)
      ans.push_back(-1);

    // if there is graeter number present on top of stack
    else if (s.size() > 0 && s.top() > nums2[i])
      ans.push_back(s.top());

    // if we have smaller number on top of stack
    else if (s.size() > 0 && s.top() < nums2[i])
    {
      // pop out numbers until stack becomes empty or you find a greater number on top of it
      while (s.size() > 0 && s.top() <= nums2[i])
        s.pop();

      // check if stack has become empty
      if (s.size() == 0)
        ans.push_back(-1);
      // else it has a greater number on top of it
      else
        ans.push_back(s.top());
    }

    // push the current number from nums2 in stack.
    s.push(nums2[i]);
  }

  // reverse the ans vector to get desired ans.
  reverse(ans.begin(), ans.end());

  int n = nums1.size();

  // for every element in nums1 find its index in nums2 and from ans vector find the next greater number and put in nums1 (our final ans)
  for (int i = 0; i < n; i++)
  {
    int idx = -1;
    for (int j = 0; j < size; j++)
    {
      if (nums1[i] == nums2[j])
      {
        idx = j;
        break;
      }
    }

    if (idx != -1)
      nums1[i] = ans[idx];
  }

  return nums1;
}

int main()
{
  vector<int> nums1 = {4, 1, 2};
  vector<int> nums2 = {1, 3, 4, 2};

  for (auto &each : nextGreaterElement(nums1, nums2))
    cout << each << " ";

  return 0;
}