// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

// Example 1:

// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
// Example 2:

// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

// solution: modified Kadane algorithm

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> maxarray(nums.size());
        vector<int> minarray(nums.size());
        
        maxarray[0] = minarray[0] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int temp = max(maxarray[i-1]*nums[i], minarray[i-1]*nums[i]);
            maxarray[i] = max(nums[i], temp);
            
            temp = min(maxarray[i-1]*nums[i], minarray[i-1]*nums[i]);
            minarray[i] = min(nums[i], temp);
        }
        
        // get the maximum element from maxarray
        return *max_element(maxarray.begin(), maxarray.end());
    }
};