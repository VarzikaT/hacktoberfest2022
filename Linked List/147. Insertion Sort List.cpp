// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/

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

class Solution
{
public:
  ListNode *insertionSortList(ListNode *head)
  {
    // points to our new sorted LL
    ListNode *newHead = NULL;

    while (head)
    {

      // removing nodes from the original LL one at a time to put in our new sorted LL
      ListNode *temp = head;
      head = head->next;
      temp->next = NULL;

      // Adding first node our LL
      if (newHead == NULL)
        newHead = temp;

      // when we encounter a node which is supposed to be at first (0th index)
      else if (newHead->val >= temp->val)
      {
        temp->next = newHead;
        newHead = temp;
      }
      // inserting node anywhere in the middle or at the end
      else
      {
        // Pointer to traverse newly created LL
        ListNode *curr = newHead;

        // traversing newly created LL and finding the correct position of temp node
        while (curr->next)
        {
          if (temp->val > curr->val and temp->val <= curr->next->val)
          {
            temp->next = curr->next;
            curr->next = temp;
            break;
          }
          curr = curr->next;
        }

        // inserting the node at the end of newly created LL
        if (curr->next == NULL)
          curr->next = temp;
      }
    }

    return newHead;
  }
};