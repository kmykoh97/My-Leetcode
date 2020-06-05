// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.

// solution: 2 pointers

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;

        if (!head->next) return nullptr;

        for (int i = 1; i <= n; i++) {
            fast = fast->next;
        }

        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast) slow->next = slow->next->next;
        else head = head->next;

        return head;
    }
};