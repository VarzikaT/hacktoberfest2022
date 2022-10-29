// 82. Remove Duplicates from Sorted List II
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include <bits/stdc++.h>
using namespace std;

// Approach 1 - Using Freq Array ✅
// Time - O(N) Space - O(N)

ListNode *deleteDuplicates(ListNode *head)
{

  if (head == NULL || head->next == NULL)
    return head;

  vector<int> freq(201, 0);

  ListNode *temp = head;

  // populating our freq array
  while (temp != NULL)
  {
    // making -ve values positive so that we can mark there freq in our array
    freq[temp->val + 100]++;
    temp = temp->next;
  }

  // making new Head pointer
  ListNode *newHead = new ListNode(0);
  // a tail pointer to keep adding the nodes at the end of our new list
  ListNode *tail = newHead;

  // creating our required list
  for (int i = 0; i < 201; i++)
  {
    if (freq[i] == 1)
    {
      // doing -100 bcoz we have done +100 to make -ve values +ve earlier so
      // in order to get the original values we do -100
      tail->next = new ListNode(i - 100);

      tail = tail->next;
    }
  }

  return newHead->next;
}
// -----------------------------------------------------------------------

// Approach 2 - Time O(N) , Space O(1) ✅
ListNode *deleteDuplicates(ListNode *head)
{

  if (head == NULL || head->next == NULL)
    return head;

  // creating our dummy node i.e prehead
  // we are giving it's value is -101 (constraints)
  ListNode *preHead = new ListNode(-101);

  // prehead's next contain head
  preHead->next = head;

  // make a current pointer point to preHead
  ListNode *curr = preHead;

  // while it not reaches to the end
  while (curr->next != NULL && curr->next->next != NULL)
  {
    // if values are equal, now we have to delete values, till when they are equal
    if (curr->next->val == curr->next->next->val)
    {
      // temp pointer to find upto when the values are equal and remove the nodes which are not be include in our answer list
      ListNode *temp = curr->next->next;

      while (temp != NULL && curr->next->val == temp->val)
      {
        ListNode *node = temp;
        temp = temp->next;

        // freeing up the memory
        delete node;
      }
      curr->next = temp;
    }

    // if values are not equal's then simply move curr to next
    else
    {
      curr = curr->next;
    }
  }

  return preHead->next;
}

int main()
{
  return 0;
}