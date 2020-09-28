// On a 2-dimensional grid, there are 4 types of squares:

// 1 represents the starting square.  There is exactly one starting square.
// 2 represents the ending square.  There is exactly one ending square.
// 0 represents empty squares we can walk over.
// -1 represents obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

 

// Example 1:

// Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
// Example 2:

// Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
// Output: 4
// Explanation: We have the following four paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
// 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
// 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
// 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
// Example 3:

// Input: [[0,1],[2,0]]
// Output: 0
// Explanation: 
// There is no path that walks over every empty square exactly once.
// Note that the starting and ending square can be anywhere in the grid.
 

// Note:

// 1 <= grid.length * grid[0].length <= 20

// solution: dfs

class Solution {
public:
    vector<vector<int>> matrix;
    int ans = 0;

    void helper(int v1, int v2, int count) {
        if (v1 < 0 || v2 < 0 || v1 >= matrix.size() || v2 >= matrix[0].size() || matrix[v1][v2] == -1 || matrix[v1][v2] == INT_MIN) return;

        if (matrix[v1][v2] == 2) {
            if (count == -1) ans++;
            return;
        }

        matrix[v1][v2] = -1;
        helper(v1-1, v2, count-1);
        helper(v1+1, v2, count-1);
        helper(v1, v2-1, count-1);
        helper(v1, v2+1, count-1);
        matrix[v1][v2] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        matrix = grid;
        int zerosCount = 0, v1, v2;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    v1 = i;
                    v2 = j;
                }

                if (grid[i][j] == 0) ++zerosCount;
            }
        }
        
        helper(v1, v2, zerosCount);
        return ans;
    }
};