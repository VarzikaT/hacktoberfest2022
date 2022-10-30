// 94. Binary Tree Inorder Traversal
// https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// Iterative Method - Using Stack
vector<int> inorderTraversal(TreeNode *root)
{

  stack<TreeNode *> st;
  TreeNode *curr = root;
  vector<int> ans;

  while (curr != NULL || !st.empty())
  {
    // going left until leaf node
    while (curr != NULL)
    {
      // pushing node into stack
      st.push(curr);

      // moving pointer to left node.
      curr = curr->left;
    }

    // popping out last leaf node
    curr = st.top();
    st.pop();

    // printing its data
    ans.push_back(curr->val);

    // going its right
    curr = curr->right;
  }

  return ans;
}