#include <iostream>
#include <vector>

using namespace std;

// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Example:

// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Note:

// You must do this in-place without making a copy of the array.
// Minimize the total number of operations.

// solution: 2 pointer approach

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pointer = 0;

        // set non-zero sequentially
        for (int num : nums) {
            if (num != 0) {
                nums[pointer] = num;
                pointer++;
            }
        }

        // set remaining elements to 0
        for (; pointer < nums.size(); pointer++) {
            nums[pointer] = 0;
        }
    }
};