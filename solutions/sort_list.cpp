// Given the head of a linked list, return the list after sorting it in ascending order.

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?

 

// Example 1:


// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:


// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105

// solution: partition

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
    ListNode* partition(ListNode* start, ListNode* end) {
        if (start == nullptr || start->next == end || start == end) return start;
        
        int val = start->val;
        ListNode* ptr = start->next;
        ListNode* previous = start;
        ListNode* head = start;

        while (ptr != end) {
            if (ptr == nullptr) break;

            if (ptr->val <= val) {
               previous->next = ptr->next;
               ptr->next = head;
               head = ptr;
               ptr = previous->next;
            } else {
                ptr = ptr->next;
                previous = previous->next; 
            }
        }
        
        ListNode* temp = partition(start->next, end);
        start->next = temp;
        head = partition(head, start);
        return head;
    }

    ListNode* sortList(ListNode* head) {
        return partition(head, nullptr);
    }
};