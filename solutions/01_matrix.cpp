// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

// The distance between two adjacent cells is 1.

 

// Example 1:

// Input:
// [[0,0,0],
//  [0,1,0],
//  [0,0,0]]

// Output:
// [[0,0,0],
//  [0,1,0],
//  [0,0,0]]
// Example 2:

// Input:
// [[0,0,0],
//  [0,1,0],
//  [1,1,1]]

// Output:
// [[0,0,0],
//  [0,1,0],
//  [1,2,1]]
 

// Note:

// The number of elements of the given matrix will not exceed 10,000.
// There are at least one 0 in the given matrix.
// The cells are adjacent in only four directions: up, down, left and right.

// solution: bfs

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> seen(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
    
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {          
                    q.push({i, j});
                    seen[i][j] = 1;        
                }
            }
        }
    
        vector<int> dirs{0, -1, 0, 1, 0};
        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            
            while (size--) {
                auto pair = q.front(); q.pop();
                int i = pair.first;
                int j = pair.second;
                ans[i][j] = steps;
                
                for (int k = 0; k < 4; ++k) {
                    int x = j + dirs[k];
                    int y = i + dirs[k + 1];
                    
                    if (x < 0 || x >= n || y < 0 || y >= m || seen[y][x]) continue;
                    
                    seen[y][x] = 1;
                    q.push({y, x});
                }
            }
            
            ++steps;
        }
    
        return ans;
    }
};