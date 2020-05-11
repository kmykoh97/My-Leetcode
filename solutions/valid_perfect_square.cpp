#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>

using namespace std;

// Given a positive integer num, write a function which returns True if num is a perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Output: true
// Example 2:

// Input: 14
// Output: false

// solution: iterative/binary search

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;

        int low = 0, high = num, mid = (low+high)/2;

        while (low <= high) {
            mid = (low+high)/2;
            float squarenum = (float)mid*(float)mid;

            if (squarenum == (float)num) return true;

            if (squarenum < (float)num) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};