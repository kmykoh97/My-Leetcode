// Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

// Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

// You may return the answer in any order.

 

// Example 1:

// Input: N = 3, K = 7
// Output: [181,292,707,818,929]
// Explanation: Note that 070 is not a valid number, because it has leading zeroes.
// Example 2:

// Input: N = 2, K = 1
// Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
 

// Note:

// 1 <= N <= 9
// 0 <= K <= 9

// solution: dfs

class Solution {
public:
    void dfs(int num, int N, int K, vector<int>& result){
        if (N == 0) {
            result.push_back(num);
            return;
        }

        int last_digit = num%10;

        if (last_digit >= K) dfs(num*10 + last_digit - K, N-1, K, result);
        if (K > 0 && last_digit + K < 10) dfs(num*10 + last_digit + K, N-1, K, result);
    }

    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> result;

        if (N == 1) result.push_back(0);

        for (int d = 1; d < 10; ++d) {
            dfs(d, N-1, K, result);
        }
        
        return result;
    }
};