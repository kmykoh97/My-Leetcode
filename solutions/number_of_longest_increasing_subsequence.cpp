// Given an integer array nums, return the number of longest increasing subsequences.

 

// Example 1:

// Input: nums = [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
// Example 2:

// Input: nums = [2,2,2,2,2]
// Output: 5
// Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

 

// Constraints:

// 0 <= nums.length <= 2000
// -106 <= nums[i] <= 106

// solution: dp

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();

        vector<int> lens(nums.size(), 1);
        vector<int> cnts(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (lens[j] + 1 > lens[i]) {
                        lens[i] = lens[j] + 1;
                        cnts[i] = cnts[j];
                    } else if (lens[j] + 1 == lens[i]) {
                        cnts[i] += cnts[j];
                    }
                }
            }
        }

        int maxLen = *max_element(lens.begin(), lens.end());        
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (lens[i] == maxLen) ans += cnts[i];
        }

        return ans;
    }
};