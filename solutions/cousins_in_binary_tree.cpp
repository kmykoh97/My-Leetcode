#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>

using namespace std;

// In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

// We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

// Return true if and only if the nodes corresponding to the values x and y are cousins.

 

// Example 1:

// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

// Input: root = [1,2,3,4], x = 4, y = 3
// Output: false
// Example 2:

// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

// Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
// Output: true
// Example 3:

// https://leetcode.com/explore/featured/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

// Input: root = [1,2,3,null,4], x = 2, y = 3
// Output: false
 

// Note:

// The number of nodes in the tree will be between 2 and 100.
// Each node has a unique integer value from 1 to 100.

// solution: BFS/DFS

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
    int levelx, levely, parentx, parenty;

    void dfs(TreeNode* root, int previousparent, int level, int x, int y) {
        if (!root) return;

        if (root->val == x) {
            levelx = level;
            parentx = previousparent;
        }

        if (root->val == y) {
            levely = level;
            parenty = previousparent;
        }

        dfs(root->left, root->val, level+1, x, y);
        dfs(root->right, root->val, level+1, x, y);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, -1, 0, x, y);

        return (levelx == levely) && (parentx != parenty);
    }
};