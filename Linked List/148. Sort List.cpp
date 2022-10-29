// 148. Sort List
// https://leetcode.com/problems/sort-list/

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

// Approach 1️⃣ Brute Force - Store all node values in vector , sort the vector and make LinkedList from it
// Time - O(NlogN)  Space - O(N)

// Approach 2️⃣ - Divide and Conquer - Merge Sort
// using two pointer - Fast and Slow find the middle node of Linkedlist
// recursively call mergeSort for the two halves
// now merge the List

ListNode *mergeLists(ListNode *left, ListNode *right)
{
  ListNode *newHead = new ListNode(0);
  ListNode *curr = newHead;

  // merging both lists
  while (left != NULL && right != NULL)
  {

    // if left list val is smaller than right list
    if (left->val <= right->val)
    {
      curr->next = left;
      left = left->next;
    }
    else
    {
      curr->next = right;
      right = right->next;
    }
    curr = curr->next;
  }

  // for unequal length lists
  if (left != NULL)
  {
    curr->next = left;
    left = left->next;
  }

  if (right != NULL)
  {
    curr->next = right;
    right = right->next;
  }

  // returning the head of new list formed
  return newHead->next;
}

ListNode *sortList(ListNode *head)
{

  // Single Node or 0 Node
  if (head == NULL || head->next == NULL)
    return head;

  ListNode *temp = NULL;
  ListNode *slow = head;
  ListNode *fast = head;

  // finding mid using fast-slow pointers
  while (fast != NULL && fast->next != NULL)
  {
    temp = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  // marking end of left half of list
  temp->next = NULL;

  // left half recursive call
  ListNode *left = sortList(head);

  // right half recursive call
  ListNode *right = sortList(slow);

  // merging both lists
  return mergeLists(left, right);
}
