// Given a linked list, swap every two adjacent nodes and return its head.

// You may not modify the values in the list's nodes. Only nodes itself may be changed.

 

// Example 1:


// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Example 2:

// Input: head = []
// Output: []
// Example 3:

// Input: head = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 100].
// 0 <= Node.val <= 100

// solution: recursive

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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;
        
        return second;
    }
};