// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

// this func delete node at given position.
ListNode *deleteAtPos(ListNode *head, int pos)
{
    if (pos == 0)
        return head;
    if (pos == 1)
    {
        head = head->next;
        return head;
    }
    ListNode *curr = head;
    int n = 0;
    
    // stopping at just before the node which has to be deleted. 
    while (n < pos - 2)
    {
        n++;
        curr = curr->next;
    }
    cout << "Curr " << curr->val;

    curr->next = curr->next->next;

    return head;
}

ListNode *removeNthFromEnd(ListNode *head, int n)
{

    ListNode *curr = head;
    int len = 0;
    // calculating the total length of List
    while (curr != NULL)
    {
        len++;
        curr = curr->next;
    }

    // if position to delete is greater than length or negetive return null. 
    if (n > len || n < 0)
        return head;

    // calculate positon to delete form start
    int pos = (len - n) + 1;

    cout << "Pos " << pos << endl;
    // calling func to delete at given postion
    return deleteAtPos(head, pos);
}
