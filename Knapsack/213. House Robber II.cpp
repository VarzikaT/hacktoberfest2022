// 213. House Robber II
// https://leetcode.com/problems/house-robber-ii/

#include <bits/stdc++.h>
using namespace std;

/*
    This problem is exactly the House Robber problem with a variation that here there can be two possibilites-
    1) Rob first house and skip last house
	  2) Rob last house and skip the first house  
	  
    Our required answer will be the max of these two possibilites. So we use dp two times - from 0 to n-2(considering first element and leaving out the last) and from 1 to n-1 (considering last element and leaving out the first)
    For any house n, Recursive relation - maxmoney[n]= max ( maxmoney[n-1] , maxmoney[n-2] + money[n-1])
 */

void printArray(vector<int> &nums)
{
  for (int i = 0; i < nums.size(); i++)
    cout << nums[i] << " ";
  cout << endl;
}

vector<int> dpstart; //house 0 to n-2
vector<int> dpend;   //house 1 to n-1

int rob(vector<int> &nums)
{
  int n = nums.size();

  if (n == 1)
    return nums[0];

  dpstart.resize(n + 1, 0);
  dpend.resize(n + 1, 0);

  dpstart[0] = 0;
  dpstart[1] = nums[0];

  dpend[1] = 0;
  dpend[2] = nums[1];

  for (int i = 2; i < n; i++)
    dpstart[i] = max(dpstart[i - 1], dpstart[i - 2] + nums[i - 1]);

  for (int i = 3; i <= n; i++)
    dpend[i] = max(dpend[i - 1], dpend[i - 2] + nums[i - 1]);

  printArray(dpstart);
  printArray(dpend);

  return max(dpstart[n - 1], dpend[n]);
}
int main()
{
  vector<int> nums = {2, 3, 2};
  cout << rob(nums);
  return 0;
}