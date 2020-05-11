#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

// Example:

// Input:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// Output: 7
// Explanation: Because the path 1→3→1→1→1 minimizes the sum.

// solution: dp

class Solution {
public:
    static int dp(vector<vector<int>>& grid, vector<vector<int>>& array, int i, int j) {
        if (i < 0 || j < 0) {
            return INT_MAX;
        } else if (array[i][j] != -1 ) {
            return array[i][j];
        } else if (i == 0 && j == 0) {
            return grid[0][0];
        } else {
            int result = min(dp(grid, array, i, j-1), dp(grid, array, i-1, j)) + grid[i][j];
            array[i][j] = result;
            return result;
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> array(grid.size(), vector<int>(grid[0].size(), -1));
        int ret;

        ret = dp(grid, array, grid.size()-1, grid[0].size()-1);

        return ret;
    }
};