// 2. Add Two Numbers
// https://leetcode.com/problems/add-two-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {

        // A dummy node which will keep head refrence of sum Linked list
        ListNode *dummyHead = new ListNode(-1);

        // first and second point to l1 and l2 respectively and tail points to last node in sum Linked list
        ListNode *first = l1, second = l2, tail = dummyHead;

        // var to store carry
        int carry = 0;

        // iterating over the two lists two create new sum linked list
        while (first != NULL || second != NULL)
        {

            // extracting the two numbers from lists to be added
            int a = (first != NULL) ? first.val : 0;
            int b = (second != NULL) ? second.val : 0;

            // adding
            int sum = a + b + carry;

            // carry generated
            carry = sum / 10;

            // other part in sum which will be stored in linked list
            int temp = sum % 10;

            // creating new ListNode and adding it to end of sum linked list
            tail->next = new ListNode(temp);

            // moving tail to last node of list
            tail = tail->next;

            // if in our first list is , node not null then move it to next node
            if (first != NULL)
                first = first->next;
            // if in our second list is , node not null then move it to next node
            if (second != NULL)
                second = second->next;
        }

        // check if after adding all nodes there is carry left or not , add it to list if its left
        if (carry > 0)
            tail->next = new ListNode(carry);

        // return the head of new sum list which was refrenced by dummyHead's next.
        return dummyHead->next;
    }
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{

    int carry = 0;

    ListNode *newHead = new ListNode(0);
    ListNode *tail = newHead;

    while (l1 != NULL && l2 != NULL)
    {
        int num1 = l1->val;
        int num2 = l2->val;

        int sum = carry + num1 + num2;

        carry = sum / 10;
        sum = sum % 10;

        tail->next = new ListNode(sum);

        tail = tail->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    cout << "Carry " << carry << endl;

    if (carry == 0)
    {
        if (l1 != NULL)
            tail->next = l1;

        if (l2 != NULL)
            tail->next = l2;
    }
    else
    {

        while (l1 != NULL)
        {
            int num1 = l1->val;
            int sum = carry + num1;

            carry = sum / 10;
            sum = sum % 10;

            tail->next = new ListNode(sum);

            tail = tail->next;
            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            int num2 = l2->val;
            int sum = carry + num2;

            carry = sum / 10;
            sum = sum % 10;

            tail->next = new ListNode(sum);

            tail = tail->next;
            l2 = l2->next;
        }
    }

    if (carry != 0)
    {
        tail->next = new ListNode(carry);
        tail = tail->next;
    }

    return newHead->next;
}