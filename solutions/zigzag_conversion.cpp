#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:

// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// solution: iterative

class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        vector<string> v(numRows);

        if (s.length() == 0 || s.length() == 1 || numRows <= 1) {
            return s;
        }

        for (int i = 0; i < s.length();) {
            int begin = 0;
            int end = numRows - 1;

            while ((i < s.length()) && (begin < numRows-1)) {
                v[begin++] += s[i++];
            }

            while ((i < s.length()) && (end > 0)) {
                v[end--] += s[i++];
            }
        }

        for (int i = 0; i < numRows; i++) {
            ans += v[i];
        }

        return ans;
    }
};