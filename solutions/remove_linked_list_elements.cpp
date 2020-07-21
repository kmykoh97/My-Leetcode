// Remove all elements from a linked list of integers that have value val.

// Example:

// Input:  1->2->6->3->4->5->6, val = 6
// Output: 1->2->3->4->5

// solution: linked list

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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *pre = new ListNode(0);
        ListNode *prehead = pre;
        pre->next = head;
        ListNode *temp = head;
        
        while (temp) {
            if (temp->val == val) {
                pre->next = temp->next;
            } else {
                pre = pre->next;
            }
            
            temp = temp->next;
        }
        
        return prehead->next;
    }
};