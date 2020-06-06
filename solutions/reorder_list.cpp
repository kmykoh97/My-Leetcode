// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

// You may not modify the values in the list's nodes, only nodes itself may be changed.

// Example 1:

// Given 1->2->3->4, reorder it to 1->4->2->3.
// Example 2:

// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

// solution: 2 pointers

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
    static ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode *back = head, *front = head->next, *temp = nullptr;

        while (front) {
            temp = front->next;
            front->next = back;
            back = front;
            front = temp;
        }

        head->next = nullptr;
        return back;
    }
    
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode *fast = head, *slow = head, *headtemp;

        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        headtemp = reverseList(slow->next);
        slow->next = nullptr;

        // merge head and headtemp alternately
        ListNode *list1 = head, *list2 = headtemp, *nlist1, *nlist2;

        while (list1 && list2) {
            nlist1 = list1->next;
            nlist2 = list2->next;
            list1->next = list2;
            list2->next = nlist1;
            list1 = nlist1;
            list2 = nlist2;
        }
    }
};