/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Input: l1 = [0], l2 = [0]
Output: [0]

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:
1. The number of nodes in each linked list is in the range [1, 100].
2. 0 <= Node.val <= 9
3. It is guaranteed that the list represents a number that does not have leading zeros.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode preHead(0), *p = &preHead;
        int extra = 0;
        while (l1 || l2 || extra)
        {
            int sum = ((l1 ? l1->val : 0) + (l2 ? l2->val : 0) + extra);
            extra = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : 0;
            l2 = l2 ? l2->next : 0;
        }
        return preHead.next;
    }
};
