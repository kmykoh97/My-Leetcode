// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:

// The solution set must not contain duplicate triplets.

// Example:

// Given array nums = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// solution: 3 pointers

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low, high;
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++) {
            int current = nums[i];
            low = i + 1;
            high = nums.size()-1;

            if (i > 0 && current == nums[i-1]) {
                continue;
            }

            while (low < high) {
                int sum = current + nums[low] + nums[high];

                if (sum == 0) {
                    result.push_back(vector<int> {nums[low], current, nums[high]});
                    low++;
                    high--;
                    while (low < high && nums[low] == nums[low-1]) low++;
                    while (low < high && nums[high] == nums[high+1]) high--;
                } else if (sum < 0) {
                    low++;
                } else if (sum > 0) {
                    high--;
                }
            }
        }

        return result;
    }
};