// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

// Example:

// Input:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// Output: 1->1->2->3->4->4->5->6

// solution: binary recursion

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
    static ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *startnode = new ListNode(0), *temp = startnode;

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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();

        if (size == 0) return nullptr;
        else if (size == 1) return lists[0];
        else if (size == 2) return mergeTwoLists(lists[0], lists[1]);
        else {
            vector<ListNode*> list1(lists.begin(), lists.begin()+size/2);
            vector<ListNode*> list2(lists.begin()+size/2, lists.end());
            return mergeTwoLists(mergeKLists(list1), mergeKLists(list2));
        }
    }
};