#include<bits/stdc++.h>
using namespace std;
/**
 * Description
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 *
 * Example
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * Solution:
     * record l1 as the answer
     * add l1 and l2 from the lowest position to the highest position
     * In each position,
     * if (val > 9) after adding, it need to carry 1 to the next position
     * do the add operation until l2 has finished adding and there is no carry
     */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head;
        head = l1;
        int value, carry = 0;
        while (l1 != NULL) {
            value = (l2 != NULL) ? l2->val : 0;
            l1->val += value + carry;

            carry =(l1->val > 9);
            if (carry)  l1->val -= 10;

            l2 = (l2 == NULL) ? NULL: l2->next;
            if (l2 == NULL && !carry) break;
            if (l1->next == NULL)  l1->next = new ListNode(0);
            l1 = l1->next;
        }
        return head;
    }
};

int main() {
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(9);
    p1->next = p2;
    p3->next = p4;
    Solution a;
    ListNode *p = a.addTwoNumbers(p1, p3);
    while (p != NULL) {
        printf("%d\n", p->val);
        p = p->next;
    }
    return 0;
}
