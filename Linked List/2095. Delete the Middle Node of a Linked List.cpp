// 2095. Delete the Middle Node of a Linked List
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

#include <bits/stdc++.h>
using namespace std;

/*  Approach - Two Pointers
    Time -O(N)  Space -O(1)
*/
ListNode *deleteMiddle(ListNode *head)
{

  if (head == NULL || head->next == NULL)
    return NULL;

  ListNode *slow = head;
  ListNode *fast = head;
  ListNode *prev;

  // getting the middle node and prev node of linked list
  while (fast != NULL && fast->next != NULL)
  {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  // cout << prev->val << endl;
  // cout << slow->val << endl;

  // skipping the middle node of linkedlist which is pointed by slow pointer
  prev->next = slow->next;
  return head;
}