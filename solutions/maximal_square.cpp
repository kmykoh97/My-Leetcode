#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example:

// Input: 

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// Output: 4

// solution: dp

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }

        int l1 = matrix.size(), l2 = matrix[0].size(), temp = 0;
        vector<vector<int>> v(l1+1, vector<int>(l2+1, 0));

        for (int i = 1; i <= l1; i++) {
            for (int j = 1; j <= l2; j++) {
                if (matrix[i-1][j-1] == '1') {
                    v[i][j] = min(min(v[i-1][j], v[i][j-1]), v[i-1][j-1]) + 1;
                    temp = max(temp, v[i][j]);
                }
            }
        }

        return temp * temp;
    }
};