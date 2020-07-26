// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

// Example:

// Input:  [1,2,1,3,2,5]
// Output: [3,5]
// Note:

// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

// solution: bit manipulation

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xy = 0;

        for (int n : nums) {
            xy ^= n;
        }

        xy &= -xy;
        vector<int> result = {0, 0};

        for (int n : nums) {
            if (xy & n) result[0] ^= n;
            else result[1] ^= n;
        }

        return result;
    }
};