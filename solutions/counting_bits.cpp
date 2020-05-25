// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

// Example 1:

// Input: 2
// Output: [0,1,1]
// Example 2:

// Input: 5
// Output: [0,1,1,2,1,2]
// Follow up:

// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

// solution: dp

class Solution {
public:
    vector<int> countBits(int num) {
        if (num == 0) return {0};
        if (num == 1) return {0, 1};
        if (num == 2) return {0, 1, 1};

        vector<int> result(num+1);
        result[0] = 0;
        result[1] = 1;
        result[2] = 1;
        int lastexp = 2;

        for (int i = 3; i <= num; i++) {
            // check if it is power of 2
            double check = log(i)/log(2);

            if (check == floor(check)) {
                result[i] = 1;
                lastexp = i;
            } else {
                result[i] = 1 + result[i-lastexp];
            }
        }

        return result;
    }
};