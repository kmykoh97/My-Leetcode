#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

// Example:

// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5

// Note:

// Only constant extra memory is allowed.
// You may not alter the values in the list's nodes, only nodes itself may be changed.

// solution: 3 pointers for linked-list reversal, recursive

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head, *current = head, *previous = nullptr, *next = nullptr;
        int noNodes = 0, n = k;

        // first count the length of linked-list
        while (temp) {
            noNodes++;
            temp = temp->next;
        }

        if (noNodes < k) {
            return head;
        }

        // next reverse the nodes in batches of k
        while (current && n--) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        // do it recursively
        if (head) {
            head->next = reverseKGroup(next, k);
        }

        return previous;
    }
};