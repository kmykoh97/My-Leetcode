// Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.
 

// Constraints:

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

// solution: dp knapsacks

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), s = 0;

        for (int i : nums) s += i;

        if (s & 1) return false;

        s /= 2;
        bool dp[s+1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;

        for (int num : nums) {
            for (int i = s; i >= num; i--) {
                dp[i] = dp[i] || dp[i-num];
                if (dp[s]) return true;
            }
        }

        return dp[s];
    }
};