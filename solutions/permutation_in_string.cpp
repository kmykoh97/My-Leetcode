#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>

using namespace std;

// Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

 

// Example 1:

// Input: s1 = "ab" s2 = "eidbaooo"
// Output: True
// Explanation: s2 contains one permutation of s1 ("ba").
// Example 2:

// Input:s1= "ab" s2 = "eidboaoo"
// Output: False
 

// Note:

// The input strings only contain lower case letters.
// The length of both given strings is in range [1, 10,000].

// solution: sliding window

class Solution {
public:
    bool checkInclusion(string p, string s) {
        vector<int> frequencytable(26, 0);
        vector<int> res;
        int count = 0;

        for (char c : p) {
            if (++frequencytable[c-'a'] == 1) ++count;
        }

        for (int i = 0, j = 0; i < s.size(); i++) {
            --frequencytable[s[i]-'a'];

            if (frequencytable[s[i]-'a'] == 0) {
                --count;
            } else if (frequencytable[s[i]-'a'] == -1) {
                ++count;
            }

            if (i-j+1 > p.size()) {
                ++frequencytable[s[j]-'a'];

                if (frequencytable[s[j]-'a'] == 1) {
                    ++count;
                } else if (frequencytable[s[j]-'a'] == 0) {
                    --count;
                }

                j++;
            }

            if (!count) return true;
        }

        return false;;
    }
};