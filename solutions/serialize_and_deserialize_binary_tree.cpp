// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

// Example: 

// You may serialize the following tree:

//     1
//    / \
//   2   3
//      / \
//     4   5

// as "[1,2,3,null,null,4,5]"
// Clarification: The above format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser_tree = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            root = q.front();
            q.pop();
            
            if (!root) {
                ser_tree += "null.";
                continue;
            }

            ser_tree += to_string(root->val) + ".";
            q.push(root->left);
            q.push(root->right);
        }

        cout << ser_tree << endl;
        return ser_tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp = "";
        
        for (char x : data) {
            if (x != '.') {
                temp += x;
            } else {
                q.push(temp);
                temp = "";
            }
        }
	 
        queue<TreeNode*> q1;
        TreeNode* root = nullptr;
        
        if (q.front() != "null") {
            cout << q.front() << endl;
            root = new TreeNode(stoi(q.front()));
            q.pop();
            q1.push(root); 
        } else {
            cout << q.front();
            return nullptr;
        }
        
        while (!q1.empty()) {
            TreeNode* temp = q1.front();
            q1.pop();
            
            if (q.front() != "null") {
                temp->left = new TreeNode(stoi(q.front()));
                q.pop();
                q1.push(temp->left);
            } else {
                temp->left = nullptr;
                q.pop();
            }
            
            if (q.front() != "null") {
                temp->right = new TreeNode(stoi(q.front()));
                q.pop();
                q1.push(temp->right);
            } else {
                temp->right = nullptr;
                q.pop();
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));