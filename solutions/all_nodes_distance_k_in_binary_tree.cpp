// We are given a binary tree (with root node root), a target node, and an integer value K.

// Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

// Output: [7,4,1]

// Explanation: 
// The nodes that are a distance 2 from the target node (with value 5)
// have values 7, 4, and 1.



// Note that the inputs "root" and "target" are actually TreeNodes.
// The descriptions of the inputs above are just serializations of these objects.
 

// Note:

// The given tree is non-empty.
// Each node in the tree has unique values 0 <= node.val <= 500.
// The target node is a node in the tree.
// 0 <= K <= 1000.

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
    unordered_map<TreeNode*, vector<TreeNode*>> g;

    void buildGraph(TreeNode* parent, TreeNode* child) {      
        if (parent) {
          g[parent].push_back(child);
          g[child].push_back(parent);
        }

        if (child->left) buildGraph(child, child->left);
        if (child->right) buildGraph(child, child->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        buildGraph(nullptr, root);    
        vector<int> ans;
        unordered_set<TreeNode*> seen;    
        queue<TreeNode*> q;
        int k = 0;

        seen.insert(target);
        q.push(target);
        
        while (!q.empty() && k <= K) {
          int s = q.size();

          while (s--) {
            TreeNode* node = q.front(); 
            q.pop();

            if (k == K) ans.push_back(node->val);    
            for (TreeNode* child : g[node]) {
              if (seen.count(child)) continue;

              q.push(child);
              seen.insert(child);
            }
          }

          ++k;
        }

        return ans;
    }
};