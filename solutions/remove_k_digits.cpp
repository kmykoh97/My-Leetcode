#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

// Note:
// The length of num is less than 10002 and will be ≥ k.
// The given num does not contain any leading zero.
// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.

// solution: stack

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length()-1;
        stack<char> s;

        for (char c : num) {
            while (!s.empty() && k > 0 && c < s.top()) {
                s.pop();
                k--;
            }

            if (!s.empty() || c != '0') {
                s.push(c);
            }
        }

        while (!s.empty() && k--) {
            s.pop();
        }

        if (s.empty()) {
            return "0";
        }

        while (!s.empty()) {
            num[n--] = s.top();
            s.pop();
        }

        return num.substr(n+1);
    }
};