#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>

using namespace std;

// Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:

// Input:
// "abccccdd"

// Output:
// 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

// solution: hashmap or set

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        bool flag = false;
        map<char, int> hashmap;
        
        for (char c : s) {
            hashmap[c]++;
        }
        
        for (auto m : hashmap) {
            while (m.second >= 2) {
                res += 2;
                m.second -= 2;
            }
            
            if (m.second == 1) {
                flag = true;
            }
        }
        
        if (flag) {
            return (res + 1);
        } else {
            return res;
        }
    }
};