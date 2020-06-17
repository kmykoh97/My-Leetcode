// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

// solution: BFS

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q, tempq;
        vector<vector<int>> result;
        vector<int> intermediate;

        if (!root) return result;

        q.push(root);

        while (!q.empty()) {
            int count = q.size();

            for (int i = 0; i < count; i++) {
                TreeNode* t = q.front();
                q.pop();
                intermediate.push_back(t->val);

                if (t->left) tempq.push(t->left);
                if (t->right) tempq.push(t->right);
            }

            result.push_back(intermediate);
            q = tempq;
            tempq = queue<int>(); // clear queue
            intermediate.clear();
        }

        return result;
    }
};