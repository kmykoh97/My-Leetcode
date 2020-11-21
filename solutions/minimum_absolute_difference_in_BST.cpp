// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

// Example:

// Input:

//    1
//     \
//      3
//     /
//    2

// Output:
// 1

// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 

// Note:

// There are at least two nodes in this BST.
// This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    vector<int> v1;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
        v1.push_back(root->val);
        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int mini = INT_MAX;

        for (int i = 0; i < v1.size()-1;i ++) mini = min(mini, abs(v1[i]-v1[i+1]));

        return mini;
    }
};