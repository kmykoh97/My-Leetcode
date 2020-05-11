#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

// You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

// Example:

// Given n = 5, and version = 4 is the first bad version.

// call isBadVersion(3) -> false
// call isBadVersion(5) -> true
// call isBadVersion(4) -> true

// Then 4 is the first bad version. 

// solution: binary search

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long left = 1, right = n;
        int mid = (left+right)/2;

        while (left <= right) {
            mid = (left+right)/2;

            if (isBadVersion(mid)) {
                if (!isBadVersion(mid-1)) {
                    return mid;
                }

                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        return mid;
    }
};