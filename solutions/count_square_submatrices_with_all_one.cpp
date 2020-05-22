// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
// Example 2:

// Input: matrix = 
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation: 
// There are 6 squares of side 1.  
// There is 1 square of side 2. 
// Total number of squares = 6 + 1 = 7.
 

// Constraints:

// 1 <= arr.length <= 300
// 1 <= arr[0].length <= 300
// 0 <= arr[i][j] <= 1

// solution: dp

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return 0; // corner case
        int result = 0;
        vector<vector<int>> dpmatrix(matrix.size(), vector<int>(matrix[0].size(), 0));

        // fill up first row and first column
        for (int i = 0; i < matrix[0].size(); i++) {
            dpmatrix[0][i] = matrix[0][i];
            result += matrix[0][i];
        }

        for (int i = 1; i < matrix.size(); i++) {
            dpmatrix[i][0] = matrix[i][0];
            result += matrix[i][0];
        }

        // start dp
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    dpmatrix[i][j] = 0;
                } else {
                    int temp = min(dpmatrix[i-1][j-1], min(dpmatrix[i][j-1], dpmatrix[i-1][j]));
                    dpmatrix[i][j] = temp + 1;
                    result += temp + 1;
                }
            }
        }

        return result;
    }
};