// You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

// The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

// Example:

// Input:
// [[0,1,0,0],
//  [1,1,1,0],
//  [0,1,0,0],
//  [1,1,0,0]]

// Output: 16

// Explanation: The perimeter is the 16 yellow stripes in the image below:

// solution: dfs

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& perimeter){
        grid[i][j] = 2;

        if (i == 0 || grid[i-1][j] == 0) perimeter++;
        if (i == grid.size() - 1 || grid[i+1][j] == 0) perimeter++;
        if (j == 0 || grid[i][j-1] == 0) perimeter++;
        if (j == grid[0].size()-1 || grid[i][j+1] == 0) perimeter++;
        if (i > 0 && grid[i-1][j] == 1) dfs(grid, i-1, j, perimeter);
        if (j > 0 && grid[i][j-1] == 1) dfs(grid, i, j-1, perimeter);
        if (i < grid.size()-1 && grid[i+1][j] == 1) dfs(grid, i+1, j, perimeter);
        if (j < grid[0].size()-1 && grid[i][j+1] == 1) dfs(grid, i, j+1, perimeter);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) dfs(grid, i, j, perimeter);
            }
        }
        
        for (int i = 0; i < grid.size(); ++i) {
            for( int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == 2) grid[i][j] = 1;
            }
        }

        return perimeter;
    }
};