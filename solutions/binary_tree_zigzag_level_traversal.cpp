// Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

// For example:
// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its zigzag level order traversal as:
// [
//   [3],
//   [20,9],
//   [15,7]
// ]

// solution: bfs

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};

        vector<vector<int>> ans;
        stack<pair<TreeNode *, int>> curr;
        stack<pair<TreeNode *, int>> next;
        curr.push(make_pair(root, 0));

        while (!empty(curr)) {
            TreeNode *node = curr.top().first;
            int level = curr.top().second;

            if (ans.size() < level+1) {
                ans.push_back(vector<int>());
            }

            ans[level].push_back(node->val);
            curr.pop();

            if (level%2 == 0) {
                if (node->left)
                    next.push(make_pair(node->left, level+1));
                if (node->right)
                    next.push(make_pair(node->right, level+1));
            } else {
                if (node->right)
                    next.push(make_pair(node->right, level+1));
                if (node->left)
                    next.push(make_pair(node->left, level+1));
            }

            if (curr.empty())
                swap(next, curr);
            
        }

        return ans;
    }
};