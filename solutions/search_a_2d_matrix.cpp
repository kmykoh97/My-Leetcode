// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
// Output: false
// Example 3:

// Input: matrix = [], target = 0
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 0 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

// solution: stair search

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;

	    int i = 0;
	    int j = matrix[0].size() - 1;

	    while (i < matrix.size() && j >= 0) {
		    if (matrix[i][j] == target) return true;
		    else if (target < matrix[i][j]) j--;
		    else i++;
		}

	    return false;
    }
};