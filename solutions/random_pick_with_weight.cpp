// Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

// For example, given an input list of values [1, 9], when we pick up a number out of it, the chance is that 9 times out of 10 we should pick the number 9 as the answer.

// Example 1:

// Input: 
// ["Solution","pickIndex"]
// [[[1]],[]]
// Output: [null,0]
// Example 2:

// Input: 
// ["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
// [[[1,3]],[],[],[],[],[]]
// Output: [null,0,1,1,1,0]
// Explanation of Input Syntax:

// The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.

 

// Constraints:

// 1 <= w.length <= 10000
// 1 <= w[i] <= 10^5
// pickIndex will be called at most 10000 times.

// solution: binary search, random

class Solution {
public:
    vector<int> v;

    Solution(vector<int>& w) {
        v.push_back(w[0]);

        for (int i = 1; i < w.size(); i++) {
            v.push_back(v.back() + w[i]);
        }
    }
    
    int pickIndex() {
        int weight = rand() % v.back();
        return upper_bound(v.begin(), v.end(), weight) - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */