#include <iostream>
#include <vector>

using namespace std;

// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

// solution: dfs

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
    static int dfs(TreeNode* root, int k) {
        if (root == nullptr) return 0;

        if (root->left == nullptr && root->right == nullptr) {
            return root->val * k;
        } else {
            return dfs(root->left, 1) + dfs(root->right, 0);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return dfs(root, 0);
    }
};