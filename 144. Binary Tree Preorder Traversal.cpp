// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Iterative Method using Stack
vector<int> postorderTraversal(TreeNode *root)
{

  vector<int> ans;

  stack<TreeNode *> st;

  TreeNode *curr = root;

  while (!st.empty() || curr != NULL)
  {

    if (curr != NULL)
    {
      st.push(curr);
      ans.push_back(curr->val);
      curr = curr->left;
    }
    else
    {
      curr = st.top(), st.pop();
      curr = curr->right;
    }
  }

  return ans;
}