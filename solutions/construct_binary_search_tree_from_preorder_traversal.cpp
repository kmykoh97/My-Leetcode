#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// Return the root node of a binary search tree that matches the given preorder traversal.

// (Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

// It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

// Example 1:

// Input: [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]

// refer to leetcode: https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3305/

// Constraints:

// 1 <= preorder.length <= 100
// 1 <= preorder[i] <= 10^8
// The values of preorder are distinct.

// solution: stack

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) return nullptr;

        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(preorder[0]);
        s.push(root);

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* treenode = new TreeNode(preorder[i]);

            if (preorder[i] <= s.top()->val) {
                s.top()->left = treenode;
                s.push(node);
            } else {
                TreeNode* temp = nullptr;

                while (!s.empty() && preorder[i] > s.top()->val) {
                    temp = s.top();
                    s.pop();
                }

                temp->right = treenode;
                s.push(treenode);
            }
        }

        return root;
    }
};