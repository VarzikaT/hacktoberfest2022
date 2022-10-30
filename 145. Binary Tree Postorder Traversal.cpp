// 145. Binary Tree Postorder Traversal
// https://leetcode.com/problems/binary-tree-postorder-traversal/

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

// Iterative Method using Two Stacks
vector<int> postorderTraversal(TreeNode *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;

  stack<TreeNode *> stk1;
  stack<TreeNode *> stk2;

  stk1.push(root);

  while (!stk1.empty())
  {
    TreeNode *curr = stk1.top();
    stk1.pop();

    stk2.push(curr);

    if (curr->left)
      stk1.push(curr->left);

    if (curr->right)
      stk1.push(curr->right);
  }

  while (!stk2.empty())
  {
    TreeNode *node = stk2.top();
    stk2.pop();
    ans.push_back(node->val);
  }

  return ans;
}
