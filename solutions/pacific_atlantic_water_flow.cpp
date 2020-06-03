// Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

// Note:

// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.
 

// Example:

// Given the following 5x5 matrix:

//   Pacific ~   ~   ~   ~   ~ 
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * Atlantic

// Return:

// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).

// solution: dfs

class Solution {
public:
    static void dfs(int i, int j, int prev, vector<vector<int>>& matrix, vector<vector<int>>& ocean) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || ocean[i][j] || prev > matrix[i][j]) return;
        
        ocean[i][j] = 1;
        dfs(i-1, j, matrix[i][j], matrix, ocean);
        dfs(i+1, j, matrix[i][j], matrix, ocean);
        dfs(i, j-1, matrix[i][j], matrix, ocean);
        dfs(i, j+1, matrix[i][j], matrix, ocean);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> result;

        if (matrix.size() == 0 || matrix[0].size() == 0) return result;

        vector<vector<int>> pacific(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> atlantic(matrix.size(), vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < matrix.size(); i++) {
            dfs(i, 0, INT_MIN, matrix, pacific);
            dfs(i, matrix[0].size()-1, INT_MIN, matrix, atlantic);
        }

        for (int i = 0; i < matrix[0].size(); i++) {
            dfs(0, i, INT_MIN, matrix, pacific);
            dfs(matrix.size()-1, i, INT_MIN, matrix, atlantic);
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};