// Given a complete binary tree, count the number of nodes.

// Note:

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Example:

// Input: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6

// Output: 6

// solution: complete binary tree

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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int llevel = 1, rlevel = 1;
        TreeNode* l = root->left;
        TreeNode* r = root->right;

        while (l) {
            l = l->left;
            llevel += 1;
        }

        while (r) {
            r = r->right;
            rlevel += 1;
        }

        if (llevel == rlevel) return pow(2, llevel) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};