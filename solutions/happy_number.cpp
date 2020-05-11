#include <iostream>
#include <vector>

using namespace std;

// Write an algorithm to determine if a number n is "happy".

// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

// Return True if n is a happy number, and False if not.

// Example: 

// Input: 19
// Output: true
// Explanation: 
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

// solution: slow fast algorithm

class Solution {
public:
    static int squaredSumOfNum(int n) {
        int ret = 0;

        for (; n != 0; n /= 10) {
            int temp = n % 10;
            ret += temp * temp;
        }

        return ret;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;

        do {
            slow = squaredSumOfNum(slow);
            fast = squaredSumOfNum(squaredSumOfNum(fast));

            if (fast == 1) return true;
        } while (slow != fast);

        return false;
    }
};