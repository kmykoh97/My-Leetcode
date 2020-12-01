// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

// solution: dfs

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;

        function<void(int)> dfs = [&](int s) {
            ans.push_back(cur);

            if (cur.size() == n) return;

            for (int i = s; i < n; ++i) {
                if (i > s && nums[i] == nums[i-1]) continue;
                cur.push_back(nums[i]);
                dfs(i+1);
                cur.pop_back();
            }
        };

        dfs(0);
        return ans;
    }
};