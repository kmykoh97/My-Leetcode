// Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

 

// Example 1:

// Input: "abab"
// Output: True
// Explanation: It's the substring "ab" twice.
// Example 2:

// Input: "aba"
// Output: False
// Example 3:

// Input: "abcabcabcabc"
// Output: True
// Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

// solution: iteration

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = s.length()/2; i > 0; i--) {
            if (s.length() % i == 0) {
                int freq = s.length() / i;
                string substring = s.substr(0, i);
                string combinedstring = "";

                for (int j = 0; j < freq; j++) {
                    combinedstring += substring;
                }

                if (combinedstring == s) return true;
            }
        }

        return false;
    }
};