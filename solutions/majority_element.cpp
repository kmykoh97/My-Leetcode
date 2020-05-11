#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>

using namespace std;

// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

// You may assume that the array is non-empty and the majority element always exist in the array.

// Example 1:

// Input: [3,2,3]
// Output: 3
// Example 2:

// Input: [2,2,1,1,1,2,2]
// Output: 2

// solution: map

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int length = nums.size();

        for (int num : nums) {
            m[num]++;

            if (m[num] > (length/2)) {
                return num;
            }
        }

        return -1; // control should never reach here
    }
};