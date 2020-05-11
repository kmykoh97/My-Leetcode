#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

// Example 1:

// Input:nums = [1,1,1], k = 2
// Output: 2
 

// Constraints:

// The length of the array is in

// solution: hashmap

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> hashmap;
        int count = 0, add = 0;

        hashmap[0] = 1;

        for (int num : nums) {
            add += num;
            int temp = add - k;

            if (hashmap.find(temp) != hashmap.end()) {
                count += hashmap[temp];
                hashmap[add]++;
            } else {
                hashmap[add]++;
            }
        }

        return count;
    }
};