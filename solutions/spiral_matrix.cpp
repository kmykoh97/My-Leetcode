// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

// Example 1:

// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:

// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

// solution: iteration

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        
        if (matrix.size() == 0) {
            return ans;
        }
        
        int rowBegin = 0;
        int rowEnd = matrix.size() - 1;
        int colBegin = 0;
        int colEnd = matrix[0].size() - 1;
        
        while (rowBegin <= rowEnd && colBegin <= colEnd) {
            for (int i = colBegin; i <= colEnd; i++) {
                ans.push_back(matrix[rowBegin][i]);
            }
            
            rowBegin++;
            
            for (int i = rowBegin; i <= rowEnd; i++) {
                ans.push_back(matrix[i][colEnd]);
            }
            
            colEnd--;
            
            if (rowBegin <= rowEnd) {
                for (int i = colEnd; i >= colBegin; i--) {
                    ans.push_back(matrix[rowEnd][i]);
                }
            }
            
            rowEnd--;
            
            if (colBegin <= colEnd) {
                for (int i = rowEnd; i >= rowBegin; i--) {
                    ans.push_back(matrix[i][colBegin]);
                }
            }
            
            colBegin++;
        }
        
        return ans;
    }
};