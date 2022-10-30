// 503. Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/

#include <bits/stdc++.h>
using namespace std;

// See code of ->  496. Next Greater Element I
//  Used similar approach as Next Graeter Element I but in this already pushed all elements of nums vector into the stack so that it can act as a circular array and simply proceeded like the Next Greater Element I Solution
//  Time O(N) , Space O(2N)

vector<int> nextGreaterElements(vector<int> &nums)
{

  int size = nums.size();
  stack<int> s;

  // pushing all elments of nums into stack s so that it can act like an circular array
  for (int i = size - 1; i >= 0; i--)
    s.push(nums[i]);

  vector<int> ans;
  for (int i = size - 1; i >= 0; i--)
  {

    // if stack is empty
    if (s.size() == 0)
      ans.push_back(-1);

    // if there is graeter number present on top of stack
    else if (s.size() > 0 && s.top() > nums[i])
      ans.push_back(s.top());

    // if we have smaller number on top of stack
    else if (s.size() > 0 && s.top() <= nums[i])
    {
      // pop out numbers until stack becomes empty or you find a greater number on top of it
      while (s.size() > 0 && s.top() <= nums[i])
        s.pop();

      // check if stack has become empty
      if (s.size() == 0)
        ans.push_back(-1);

      // else it has a greater number on top of it
      else
        ans.push_back(s.top());
    }

    // push the current number from nums2 in stack.
    s.push(nums[i]);
  }

  // reverse the ans vector to get desired ans.
  reverse(ans.begin(), ans.end());

  return ans;
}

int main()
{
  vector<int> nums = {1, 3, 4, 2};

  for (auto &each : nextGreaterElements(nums))
    cout << each << " ";
  return 0;
}