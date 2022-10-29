// 1290. Convert Binary Number in a Linked List to Integer
// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Approach - use a stack to store values from linked list and then pop out values to convert binary into decimal
// Time O(N) , Space O(N);

int getDecimalValue(ListNode *head)
{
  stack<int> st;

  if (head == NULL)
    return 0;

  ListNode *curr = head;

  while (curr != NULL)
  {
    st.push(curr->val);
    curr = curr->next;
  }

  int i = 0;
  int ans = 0;
  while (!st.empty())
  {
    int num = st.top();
    st.pop();
    ans = ans + (num * pow(2, i));
    i++;
  }

  return ans;
}
