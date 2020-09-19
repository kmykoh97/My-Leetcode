// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Note:

// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

// solution: combination

class Solution {
public:
    vector<vector<int>> result;

    void try_combination(vector<int>& combination, int k, int n, int start){
        if (k == combination.size()) {
            if (n == 0) result.push_back(combination);
            return;
        }

        for (int i = start; i <= 9; ++i) {
            combination.push_back(i);
            try_combination(combination, k, n-i, i+1);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combination;
        try_combination(combination, k, n, 1);
        return result;
    }
};