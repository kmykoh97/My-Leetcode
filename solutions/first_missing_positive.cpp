// Given an unsorted integer array, find the smallest missing positive integer.

// Example 1:

// Input: [1,2,0]
// Output: 3
// Example 2:

// Input: [3,4,-1,1]
// Output: 2
// Example 3:

// Input: [7,8,9,11,12]
// Output: 1
// Follow up:

// Your algorithm should run in O(n) time and uses constant extra space.

// solution: negation

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool flag = true;
        int i = 0;

        for (int num : nums) {
            if (num == 1) flag = false;
        }

        if (flag) return 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0 || nums[i] > nums.size()) nums[i] = 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[abs(nums[i])-1] = abs(nums[abs(nums[i])-1]) * (-1);
            }
        }

        while (i < nums.size() && nums[i] <= 0) i++;

        return i+1;
    }
};