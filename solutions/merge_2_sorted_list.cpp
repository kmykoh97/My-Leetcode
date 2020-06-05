// Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

// solution: linked-list

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *startnode = l1->val < l2->val ? l1 : l2, *temp = startnode;

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                temp->next = l1;
                l1 = l1->next;
                temp = temp->next;
            } else {
                temp->next = l2;
                l2 = l2->next;
                temp = temp->next;
            }
        }

        if (l1) temp->next = l1;
        if (l2) temp->next = l2;

        return startnode->next;
    }
};