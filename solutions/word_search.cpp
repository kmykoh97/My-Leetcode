// Given a 2D board and a word, find if the word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example:

// board =
// [
//   ['A','B','C','E'],
//   ['S','F','C','S'],
//   ['A','D','E','E']
// ]

// Given word = "ABCCED", return true.
// Given word = "SEE", return true.
// Given word = "ABCB", return false.
 

// Constraints:

// board and word consists only of lowercase and uppercase English letters.
// 1 <= board.length <= 200
// 1 <= board[i].length <= 200
// 1 <= word.length <= 10^3

// solution: dfs

class Solution {
public:
    static bool dfs(const string& word, int begin, const vector<vector<char>>& board, int i, int j, vector<vector<int>>& hist){
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[begin] != board[i][j]) return false;
        if (word.size()-1 == begin) return true;

        hist[i][j] = 1;

        if ((i-1 >= 0 && i-1 < hist.size() && j >= 0 && j < hist[0].size()) && !hist[i-1][j] && dfs(word, begin+1, board, i-1, j, hist)) return true;
        if ((i+1 >= 0 && i+1 < hist.size() && j >= 0 && j < hist[0].size()) && !hist[i+1][j] && dfs(word, begin+1, board, i+1, j, hist)) return true;
        if ((i >= 0 && i < hist.size() && j-1 >= 0 && j-1 < hist[0].size()) && !hist[i][j-1] && dfs(word, begin+1, board, i, j-1, hist)) return true;
        if ((i >= 0 && i < hist.size() && j+1 >= 0 && j+1 < hist[0].size()) && !hist[i][j+1] && dfs(word, begin+1, board, i, j+1, hist)) return true;

        hist[i][j] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> hist(board.size(), vector<int>(board[0].size(), 0));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && dfs(word, 0, board, i, j, hist)) return true;
            }
        }

        return false;
    }
};