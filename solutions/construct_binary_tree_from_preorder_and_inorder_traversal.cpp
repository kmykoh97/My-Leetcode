// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]
// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// solution: inorder, preorder

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
    static TreeNode* build(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int i;

        if (preorder.size() == 1) return root;
        
        for (i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root->val) break;
        }
            
        if (i == 0) {
            vector<int> preright(preorder.begin()+1, preorder.end());
            vector<int> inright(inorder.begin()+1, inorder.end());
            root->right = build(preright, inright);
            return root;
        }
            
        if (i == inorder.size()-1) {
            vector<int> preleft(preorder.begin()+1, preorder.end());
            vector<int> inleft(inorder.begin(), inorder.end()-1);
            root->left = build(preleft, inleft);
            return root;
        }

        vector<int> preright(preorder.begin()+i+1, preorder.end());
        vector<int> inright(inorder.begin()+i+1, inorder.end());
        root->right = build(preright, inright);
        vector<int> preleft(preorder.begin()+1, preorder.begin()+i+1);
        vector<int> inleft(inorder.begin(), inorder.begin()+i);
        root->left=build(preleft, inleft);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() && inorder.empty()) return nullptr;

        return build(preorder, inorder);
    }
};