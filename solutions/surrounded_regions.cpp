// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.

// Example:

// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X
// Explanation:

// Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

// solution: DFS

class Solution {
public:
    static void DFS(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;

        if (board[i][j] == 'V' || board[i][j] == 'X') return;

        board[i][j] = 'V';
        
        DFS(board, i+1, j);
        DFS(board, i-1, j);
        DFS(board, i, j+1);
        DFS(board, i, j-1);
    }
    
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (i == 0 || i == board.size()-1 || j == 0 || j == board[0].size()-1) {
                    if (board[i][j] != 'V' && board[i][j] == 'O') DFS(board, i, j);
                }
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] = (board[i][j] == 'V' ? 'O' : 'X');
            }
        }
    }
};