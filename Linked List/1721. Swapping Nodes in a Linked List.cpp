// 1721. Swapping Nodes in a Linked List
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    // Approach - Using Vector
    //  Transforming the linkedlist into a vector and then swapping the nodes and then transform back them into a linked list
    ListNode *swapNodes(ListNode *head, int k)
    {

        vector<int> v;
        ListNode *temp = head;

        // soring values into vector
        while (temp != NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        int size = v.size();

        if (size == 0 || size == 1)
            return head;

        // swappping
        swap(v[k - 1], v[size - k]);

        // head of new linkedList
        ListNode *newHead = new ListNode(v[0]);

        // pointer which always points to last of LinkedList
        ListNode *last = newHead;

        // creating a linkedList
        for (int i = 1; i < v.size(); i++)
        {
            last->next = new ListNode(v[i]);
            last = last->next;
        }

        // returning the head;
        return newHead;
    }

    // -------------------------------------------------------------------------------------
    // Approach - Finding the kth nodes and swapping using the inbuilt swap function
    // Time O(N) , Space O(1)
    //  function to find kth element from start
    ListNode *kthStart(ListNode *head, int k)
    {
        ListNode *curr = head;
        while (k - 1 > 0)
        {
            k--;
            curr = curr->next;
        }

        // cout << curr->val <<endl;
        return curr;
    }

    // function to find kth element from end;
    ListNode *kthEnd(ListNode *head, int k)
    {
        ListNode *curr = head;
        int size = 1;

        // calculating total size of list
        while (curr->next != NULL)
        {
            size++;
            curr = curr->next;
        }

        // cout << size<<endl;
        // position of kth element from start.
        int n = size - k + 1;

        // getting kth element form start
        return kthStart(head, n);
    }

    ListNode *swapNodes2(ListNode *head, int k)
    {

        ListNode *first = kthStart(head, k);
        ListNode *second = kthEnd(head, k);

        // swapping both elements
        swap(first->val, second->val);

        return head;
    }
};