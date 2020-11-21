// Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// For example:
// Given BST [1,null,2,2],

//    1
//     \
//      2
//     /
//    2
 

// return [2].

// Note: If a tree has more than one mode, you can return them in any order.

// Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

// solution: inorder traversal

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
    vector<int> v;
    int maxfreq = 0;

    void inorder(TreeNode* root, TreeNode* &pre, int &currentfreq) {
        if (!root) return;

        inorder(root->left, pre, currentfreq);
        currentfreq = (pre && root->val == pre->val ? currentfreq+1 : 1);

        if (currentfreq == maxfreq) v.push_back(root->val);
        else if (currentfreq > maxfreq) {
            v.clear();
            v.push_back(root->val);
            maxfreq = currentfreq;
        }

        pre = root;
        inorder(root->right, pre, currentfreq);
    }

    vector<int> findMode(TreeNode* root) {
        TreeNode* pre = nullptr;
        int currentfreq = 0;
        inorder(root, pre, currentfreq);
        return v;
    }
};