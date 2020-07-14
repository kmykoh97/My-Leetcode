// Given a set of distinct integers, nums, return all possible subsets (the power set).

// Note: The solution set must not contain duplicate subsets.

// Example:

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

// solution: dfs

class Solution {
public:
    static void dfs(vector<int> nums, vector<int> &output, int currentIndex, vector<vector<int>> &answer) {
        output.push_back(nums[currentIndex]);
        answer.push_back(output);

        while (++currentIndex < nums.size()) {
            dfs(nums, output, currentIndex, answer);
        }

        output.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> output;
        answer.push_back(output);

        for (int i = 0; i < nums.size(); i++) {
            dfs(nums, output, i, answer);
        }

        return answer;
    }
};