// 143. Reorder List
// https://leetcode.com/problems/reorder-list/

#include <bits/stdc++.h>
using namespace std;

/*  Approach - Two Pointers -  Reversing the other half of linked List and merging them alternatively
    Time - O(N) Space - O(1)
*/

// func to reverse the list and return the head;
ListNode *reverseList(ListNode *head)
{
  if (head == NULL)
    return NULL;

  ListNode *c = head;
  ListNode *p = NULL;
  ListNode *n = head->next;

  while (c != NULL)
  {
    c->next = p;
    p = c;
    c = n;
    if (n != NULL)
      n = n->next;
  }

  return p;
}

void reorderList(ListNode *head)
{
  // if list has 2 or less than 2 nodes
  if (head == NULL || head->next == NULL || head->next->next == NULL)
    return;

  ListNode *slow = head;
  ListNode *fast = head;

  // find the mid using slow and fast pointer technique
  while (fast->next != NULL && fast->next->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }

  ListNode *mid = slow->next;
  slow->next = NULL;

  // reverse the other half of the list
  mid = reverseList(mid);

  // pointers pointing to head of both lists
  ListNode *p1 = head;
  ListNode *p2 = mid;

  // iterate over the two lists and merge them alternatively one by one
  while (p2 != NULL)
  {
    // storing the next nodes of both the lists
    ListNode *a = p1->next;
    ListNode *b = p2->next;

    // conencted the nodes of list
    p1->next = p2;
    p2->next = a;

    // moving the pointer forward to next nodes
    p1 = a;
    p2 = b;
  }
}
