// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

// Example:

// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7

// solution: 

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
    ListNode* insertAtHead(ListNode* &head , ListNode* &n){
        if (!head) return n;
    
        n->next = head;
        head = n;

        return head;
    }   

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;

        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* l3 = nullptr;

        while (!s1.empty() && !s2.empty()) {
            int val = s1.top() + s2.top() + carry;
            s1.pop();
            s2.pop();
            carry = val/10;
            val %= 10;
            ListNode* n = new ListNode(val);
            l3 = insertAtHead(l3, n);
        }

        while (!s1.empty()) {
            int val = s1.top() + carry;
            s1.pop();
            carry = val/10;
            val %= 10;
            ListNode* n = new ListNode(val);
            l3 = insertAtHead(l3, n);
        }

        while (!s2.empty()) {
            int val = s2.top() + carry;
            s2.pop();
            carry = val/10;
            val %= 10;
            ListNode* n = new ListNode(val);
            l3 = insertAtHead(l3, n);
        }

        if (carry != 0) {
            ListNode* n = new ListNode(carry);
            l3 = insertAtHead(l3, n);
        }
        
        return l3;
    }
};