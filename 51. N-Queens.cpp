// 51. N-Queens
// https://leetcode.com/problems/n-queens/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
  bool canBePlacedHere(int n, vector<string> &v, int row, int col)
  {
    // for same col upper elements
    for (int i = 0; i < row; i++)
    {
      if (v[i][col] == 'Q')
        return false;
    }

    // check for upper left diagonal elements
    int x = row - 1, y = col - 1;
    while (x >= 0 and y >= 0)
    {
      if (v[x][y] == 'Q')
        return false;

      x--, y--;
    }

    // check for upper right diagonal elements
    x = row - 1;
    y = col + 1;

    while (x >= 0 and y < n)
    {
      if (v[x][y] == 'Q')
        return false;

      x--, y++;
    }

    // if any of the above cases are not returning false that means queen can be placed at that location
    return true;
  }

  void solve(vector<vector<string>> &ans, vector<string> v, int n, int row)
  {
    // base case
    if (row == n)
    {
      ans.push_back(v);
      return;
    }

    for (int col = 0; col < n; col++)
    {

      if (canBePlacedHere(n, v, row, col))
      {
        v[row][col] = 'Q';
        solve(ans, v, n, row + 1);
        v[row][col] = '.';
      }
    }

    return;
  }

public:
  vector<vector<string>> solveNQueens(int n)
  {
    vector<vector<string>> ans;
    vector<string> v(n);
    string s(n, '.');

    for (int i = 0; i < n; i++)
      v[i] = s;

    solve(ans, v, n, 0);

    return ans;
  }
};

int main()
{

  Solution obj;
  vector<vector<string>> ans = obj.solveNQueens(4);

  for (auto &str : ans)
  {
    for (auto &i : str)
      cout << i << endl;
    cout << endl;
  }
  return 0;
}