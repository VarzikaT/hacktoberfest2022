// 61. Rotate List
// https://leetcode.com/problems/rotate-list/

#include <bits/stdc++.h>
using namespace std;

// Approach - Optimal Solution 🔥
// Step 1 - Reversing the whole List
// Step 2 - Reversing the first K nodes
// Step 3 - Reversing the remaining nodes after Kth Node

// Edge case 1 - If K is greater than N make it in range 0 - N by Subtracting N from it until it becomes equal or less
// Edge case 2 - if List size is 0 or 1 or if k is 0 or equal to size return original head

// Time - O(N)  Space - O(1)

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// func which reverses List till n Nodes
ListNode *reverseTillNthNode(ListNode *head, int n)
{
  if (head == NULL || head->next == NULL)
    return head;

  ListNode *PREV = NULL;
  ListNode *CURR = head;
  ListNode *NEXT = head->next;

  while (CURR != NULL && n--)
  {
    CURR->next = PREV;
    PREV = CURR;
    CURR = NEXT;

    if (NEXT != NULL)
      NEXT = NEXT->next;
  }

  return PREV;
}

ListNode *rotateRight(ListNode *head, int k)
{

  ListNode *temp = head;

  int size = 0;

  // getting size of our linked list
  while (temp != NULL)
  {
    size++;
    temp = temp->next;
  }

  // edge cases
  if (head == NULL || head->next == NULL || k == 0 || k == size)
    return head;

  // updating k to make it in rnage of linked list size
  k = k % size;

  // reversing the whole list
  temp = reverseTillNthNode(head, size);

  ListNode *rightList = temp;
  int n = k;

  // moving pointer to node after kth node to reverse the list(rightList) after Kth node
  while (rightList != NULL && n > 0)
  {
    rightList = rightList->next;
    n--;
  }

  // reversing left List
  ListNode *leftList = reverseTillNthNode(temp, k);

  // making our new head
  ListNode *newHead = leftList;

  // reversing right list
  rightList = reverseTillNthNode(rightList, size - k);

  // moving pointer to end of left list
  while (leftList->next != NULL)
  {
    leftList = leftList->next;
  }
  // joining both the list
  leftList->next = rightList;

  // returning the new head
  return newHead;
}
