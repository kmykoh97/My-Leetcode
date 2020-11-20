// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:


// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.
// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]
 

// Constraints:

// The number of nodes in each linked list is in the range [1, 100].
// 0 <= Node.val <= 9
// It is guaranteed that the list represents a number that does not have leading zeros.

// solution: linked list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val = 0, carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* last = dummy;
        
        while (l1 && l2) {
            val = l1->val + l2->val + carry;
            ListNode* node = new ListNode(val%10);
            last->next = node;
            last = last->next;
            carry = val/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode* iter = l1 == nullptr ? l2 : l1;
        
        while (iter) {
            val = carry + iter->val;
            ListNode* node = new ListNode(val%10);
            carry = val/10;
            last->next = node;
            last = last->next;
            iter = iter->next;
        }

        if (carry) last->next = new ListNode(carry);
        
        return dummy->next;
    }
};