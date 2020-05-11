#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

// Example:

// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

// Note: Please solve it without division and in O(n).

// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

// solution: 2 direction calculation

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int temp = 1;
        vector<int> list(nums.size(), 0);
        list[0]  = 1;

        for (int i = 1; i < nums.size(); i++) {
            list[i] = list[i-1] * nums[i-1];
        }

        for (int i = nums.size()-1; i >= 0; i--) {
            list[i] *= temp;
            temp = temp * nums[i];
        }

        return list;
    }
};