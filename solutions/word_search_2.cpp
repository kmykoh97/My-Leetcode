// Given a 2D board and a list of words from the dictionary, find all words in the board.

// Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

// Example:

// Input: 
// board = [
//   ['o','a','a','n'],
//   ['e','t','a','e'],
//   ['i','h','k','r'],
//   ['i','f','l','v']
// ]
// words = ["oath","pea","eat","rain"]

// Output: ["eat","oath"]
 

// Note:

// All inputs are consist of lowercase letters a-z.
// The values of words are distinct.

// solution: trie + dfs

class Solution {
public:
    struct node {
        char c;
        int ends;
        string word;
        node *child[26];
    };

    struct node *getNode(char c) {
        node *newnode = new node;
        newnode->c = c;
        newnode->ends = 0;
        newnode->word = "";

        for (int i = 0; i < 26; ++i) {
            newnode->child[i] = nullptr;
        }

        return newnode;
    }

    node *root = getNode('/');
    
    void insert(string s) {
        node *curr=root;
        int index, i = 0;

        while (s[i]) {
            index = s[i]-'a';

            if (curr->child[index] == nullptr) {
                curr->child[index] = getNode(s[i]);
            }
            
            curr = curr->child[index];
            i += 1;
        }

        curr->ends += 1;
        curr->word = s;
    }

    void solve(vector<vector<char>>& board,int i,int j,int r,int c,vector<string>& ans,node *curr) {
        int index = board[i][j] - 'a';

        if (board[i][j] == '$' || curr->child[index] == nullptr) return;
        
        curr = curr->child[index];

        if (curr->ends > 0) {
            ans.push_back(curr->word);
            curr->ends -= 1;
        }
        
        char ch = board[i][j];
        board[i][j] = '$';
        
        if (i > 0) solve(board, i-1, j, r, c, ans, curr);
        if (i < r-1) solve(board, i+1, j, r, c, ans, curr);
        if (j > 0) solve(board, i, j-1, r, c, ans, curr);
        if (j < c-1) solve(board, i, j+1, r, c, ans, curr);
        
        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int r = board.size();
        int c = board[0].size();
        
        for (int i = 0; i < words.size(); ++i) {
            insert(words[i]);
        }
        
        vector<string> ans;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                solve(board, i, j, r, c, ans, root);
            }
        }

        return ans;
    }
};