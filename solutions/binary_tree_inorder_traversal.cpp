// Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

// Example 1:


// Input: root = [1,null,2,3]
// Output: [1,3,2]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
// Example 4:


// Input: root = [1,2]
// Output: [2,1]
// Example 5:


// Input: root = [1,null,2]
// Output: [1,2]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 

// Follow up:

// Recursive solution is trivial, could you do it iteratively?

// solution: stack

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /* recursive solution
    void helper(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        helper(root, ans);
        
        return ans;
    }
    */
    
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> data;
        vector<int> ans;

        if (root == nullptr) return ans;
        
        data.push(root);

        while (!data.empty()) {
            root = data.top();
            
            if (root->left) {
                data.push(root->left);
                root->left = nullptr;
            } else {
                ans.push_back(root->val);
                data.pop();
                if (root->right) data.push(root->right);
            }
        }

        return ans;
    }
};