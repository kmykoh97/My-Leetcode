#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

// solution: binary search

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        
        if (nums.size() == 0) return -1;

        while (right >= left) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) return mid;

            if (nums[mid] <= nums.back()) {
                if (nums[mid] < target && target <= nums.back()) {
                    left = mid + 1;
                    continue;
                }

                right = mid - 1;
            } else {
                if (nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                    continue;
                }

                left = mid + 1;
            }
        }

        return -1;
    }
};