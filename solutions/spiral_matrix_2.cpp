// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

// Example 1:


// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 20

// solution: iteration

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        
        
        int rowBegin = 0;
        int rowEnd = n-1;
        int colBegin = 0;
        int colEnd = n-1;
        int counter = 1;
        
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int i = colBegin; i <= colEnd; i++) {
                ans[rowBegin][i] = counter;
                counter++;
            }
            
            rowBegin++;
            
            for (int i = rowBegin; i <= rowEnd; i++) {
                ans[i][colEnd] = counter;
                counter++;
            }
            
            colEnd--;
            
            if (rowBegin <= rowEnd) {
                for (int i = colEnd; i >= colBegin; i--) {
                    ans[rowEnd][i] = counter;
                    counter++;
                }
            }
            
            rowEnd--;
            
            if (colBegin <= colEnd) {
                for (int i = rowEnd; i >= rowBegin; i--) {
                    ans[i][colBegin] = counter;
                    counter++;
                }
            }
            
            colBegin++;
        }
        
        return ans;
    }
};