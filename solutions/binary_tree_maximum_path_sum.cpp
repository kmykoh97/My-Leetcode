#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// Given a non-empty binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

// Example 1:

// Input: [1,2,3]

//        1
//       / \
//      2   3

// Output: 6
// Example 2:

// Input: [-10,9,20,null,null,15,7]

//    -10
//    / \
//   9  20
//     /  \
//    15   7

// Output: 42

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
    int maxPath = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) {
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        if (left < 0) left = 0;
        if (right < 0) right = 0;

        int temp1 = left + right + root->val;
        int temp2 = max(left, right) + root->val;
        maxPath = max(maxPath, temp1);

        return temp2;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);

        return maxPath;
    }
};