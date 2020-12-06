// Given an array of integers nums and a positive integer k, find whether it's possible to divide this array into k non-empty subsets whose sums are all equal.

 

// Example 1:

// Input: nums = [4, 3, 2, 3, 5, 2, 1], k = 4
// Output: True
// Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
 

// Note:

// 1 <= k <= len(nums) <= 16.
// 0 < nums[i] < 10000.

// solution: dfs

class Solution {
public:
    bool dfs(const vector<int>& nums, int target, int cur, int k, int used) {
        if (k == 0) return (used == (1 << nums.size())-1);

        for (int i = 0; i < nums.size(); ++i) {
            if (used & (1 << i)) continue;
            int t = cur+nums[i];
            if (t > target) break;
            int new_used = used | (1 << i);
            if (t == target && dfs(nums, target, 0, k-1, new_used)) return true; 
            else if (dfs(nums, target, t, k, new_used)) return true;
        }
        
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;    
        sort(nums.begin(), nums.end());    
        
        return dfs(nums, sum/k, 0, k, 0);
    }
};