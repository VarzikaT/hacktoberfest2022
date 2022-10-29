// 24. Swap Nodes in Pairs
//

#include <bits/stdc++.h>
using namespace std;

/*  Approach - Using Recursion
    Time - O(N) Space - O(1)
*/

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
  ListNode *swapPairs(ListNode *head)
  {

    //base case
    if (head == NULL || head->next == NULL)
      return head;

    // adjacent pointer to next node of head;
    ListNode *adjacent = head->next;

    // changing links here
    // passing next node of adjacent node i.e. head of next pair to swap
    // Node which will be returned will be put to next of head
    head->next = swapPairs(head->next->next);

    // make adjacent->next to head
    adjacent->next = head;

    // return the adjacent
    // bcoz after chnaging links adjacent acts as out new head
    return adjacent;
  }
};