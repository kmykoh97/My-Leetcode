// Given a binary tree, return the sum of values of its deepest leaves.
 

// Example 1:



// Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
// Output: 15
 

// Constraints:

// The number of nodes in the tree is between 1 and 10^4.
// The value of nodes is between 1 and 100.

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
    void dfs(TreeNode* root, int &maxLevel, int &ans, int currentLevel) {
        if (!root) return;

        if (!root->left && !root->right) {
            if (currentLevel == maxLevel) ans += root->val;
            else if (currentLevel > maxLevel) {
                ans = root->val;
                maxLevel = currentLevel;
            }
        }

        dfs(root->left, maxLevel, ans, currentLevel+1);
        dfs(root->right, maxLevel, ans, currentLevel+1);
    }

    int deepestLeavesSum(TreeNode* root) {
        int ans = 0, maxLevel = 0;
        dfs(root, maxLevel, ans, 0);
        return ans;
    }
};