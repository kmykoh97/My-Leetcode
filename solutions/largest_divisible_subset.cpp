// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

// Si % Sj = 0 or Sj % Si = 0.

// If there are multiple solutions, return any subset is fine.

// Example 1:

// Input: [1,2,3]
// Output: [1,2] (of course, [1,3] will also be ok)
// Example 2:

// Input: [1,2,4,8]
// Output: [1,2,4,8]

// solution: recursion or dp

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // first we need to complete dp table just like longest increasing subsequence problem
        vector<int> dp(nums.size()+1, 1); // set to 1 because every number is divisible by itself
        vector<int> res;
        int largestnum = 1;

        if (nums.size() == 0) return res;

        sort(nums.begin(), nums.end()); // O(nlog(n))
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    dp[i] = max(dp[i], 1+dp[j]);
                    largestnum = max(largestnum, dp[i]);
                }
            }
        }

        // next need to get the values
        int previous = -1;

        for (int i = nums.size()-1; i >= 0; i--) {
            if (dp[i] == largestnum && (previous == -1 || previous%nums[i] == 0)) {
                res.push_back(nums[i]);
                previous = nums[i];
                largestnum--;
            }
        }

        return res;
    }
};