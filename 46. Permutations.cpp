// 46. Permutations
// https://leetcode.com/problems/permutations/

#include <bits/stdc++.h>
using namespace std;

//----------------------Approach 1 ----------- Using Map to mark visited
// Time O(N! * N)

// vector of vector to store all permutations
vector<vector<int>> res;
// vector to store each permutations.
vector<int> permu;

void solve(vector<int> &nums, vector<int> &map)
{
  if (permu.size() == nums.size())
  {
    res.push_back(permu);
    return;
  }

  // this loop will ensure that index dosen't goes out of bounds .
  for (int i = 0; i < nums.size(); i++)
  {
    // checking if we have previously viisted that index or not.
    if (!map[i])
    {
      // push the element into permu array.
      permu.push_back(nums[i]);

      // mark curr index as visited.
      map[i] = 1;

      // recursive call.
      solve(nums, map);

      // mark curr index as unvisited
      map[i] = 0;

      // remove the element from permu array
      permu.pop_back();
    }
  }
}

vector<vector<int>> permute(vector<int> &nums)
{
  vector<int> map(7, 0);
  solve(nums, map);
  return res;
}

// Approach 2 -------------------- swapping indexes for possible permutations
// Time - O( N! * N) , Space O(N!) (stack space)
void generatePermuteBySwap(int idx, vector<int> &nums, vector<vector<int>> &ans)
{
  if (idx == nums.size())
  {
    ans.push_back(nums);
    return;
  }

  for (int i = idx; i < nums.size(); i++)
  {
    // swaping current idx with all possible i (genrating permutations for idx )
    swap(nums[i], nums[idx]);

    // recursive call for next idx
    generatePermuteBySwap(idx + 1, nums, ans);

    // making nums as it was before swapping
    swap(nums[i], nums[idx]);
  }
}

vector<vector<int>> permuteBySwapping(vector<int> &nums)
{

  vector<vector<int>> ans;

  generatePermuteBySwap(0, nums, ans);

  return ans;
}

int main()
{
  vector<int> nums = {1, 2, 3};

  // vector<vector<int>> ans = permute(nums);

  vector<vector<int>> ans = permuteBySwapping(nums);

  for (auto &perm : ans)
  {
    for (auto &each : perm)
      cout << each << " ";
    cout << endl;
  }
  return 0;
}