#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// Note: The length of the given binary array will not exceed 50,000.

// solution: hashmap

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxLength = 0, mapSum = 0;
        unordered_map<int, int> map;

        map[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) mapSum--;

            if (nums[i] == 1) mapSum++;

            if (map.find(mapSum) != map.end()) {
                maxLength = max(maxLength, i - map[mapSum]);
            } else {
                map[mapSum] = i;
            }
        }

        return maxLength;
    }
};