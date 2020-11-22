// Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.

// The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

// If no land or water exists in the grid, return -1.

 

// Example 1:



// Input: [[1,0,1],[0,0,0],[1,0,1]]
// Output: 2
// Explanation: 
// The cell (1, 1) is as far as possible from all the land with distance 2.
// Example 2:



// Input: [[1,0,0],[0,0,0],[0,0,0]]
// Output: 4
// Explanation: 
// The cell (2, 2) is as far as possible from all the land with distance 4.
 

// Note:

// 1 <= grid.length == grid[0].length <= 100
// grid[i][j] is 0 or 1

// solution: bfs

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int visited[n][m];

        memset(visited, 0, sizeof(visited));
        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1){
                    visited[i][j] = 1;
                    q.push({0, {i, j}});
                }
            }
        }

        int maxx = 0 ;
        vector<pair<int, int>> dxy = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (q.empty() == false) {
            auto it = q.front();
            q.pop();
            int currlevel = it.first;
            int x = it.second.first;
            int y = it.second.second;

            for (int i = 0; i < dxy.size(); ++i) {
                int newx = x + dxy[i].first;
                int newy = y + dxy[i].second;
                if (newx < 0 || newx >= n || newy < 0 || newy >= m || visited[newx][newy] == 1 || grid[newx][newy] == 1) continue;
                visited[newx][newy] = 1;
                q.push({currlevel+1, {newx, newy}});
                maxx = max(maxx, currlevel+1);
            }
        }

        if (maxx == 0) return -1;
        return maxx;
    }
};