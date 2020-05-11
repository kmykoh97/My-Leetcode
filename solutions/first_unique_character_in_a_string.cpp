#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>

using namespace std;

// Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

// Examples:

// s = "leetcode"
// return 0.

// s = "loveleetcode",
// return 2.
// Note: You may assume the string contain only lowercase letters.

// solution: map

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;

        for (char c : s) {
            m[c]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (m[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};