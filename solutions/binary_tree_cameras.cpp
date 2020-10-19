// Given a binary tree, we install cameras on the nodes of the tree. 

// Each camera at a node can monitor its parent, itself, and its immediate children.

// Calculate the minimum number of cameras needed to monitor all nodes of the tree.

 

// Example 1:


// Input: [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.
// Example 2:


// Input: [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.

// Note:

// The number of nodes in the given tree will be in the range [1, 1000].
// Every node has value 0.

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
    int nCamera = 0;

    pair<bool, bool> cnt_camera(TreeNode* root) {
        if (!root) return {false, true};
    
        pair<bool, bool> L = cnt_camera(root->left);
        pair<bool, bool> R = cnt_camera(root->right);
    
        bool has_cam = false;
        bool monitored = false;
        
        if (L.first || R.first) monitored = true;
    
        if (!L.second || !R.second ) {
            has_cam = true;
            monitored = true;
            nCamera++;
        }
    
        return {has_cam, monitored};
    }

    int minCameraCover(TreeNode* root) {
        pair<bool, bool> temp = cnt_camera(root);
        
        if (!temp.second) nCamera++;

        return nCamera;
    }
};