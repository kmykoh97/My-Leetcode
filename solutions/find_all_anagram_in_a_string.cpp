#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>

using namespace std;

// Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

// Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

// The order of output does not matter.

// Example 1:

// Input:
// s: "cbaebabacd" p: "abc"

// Output:
// [0, 6]

// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".
// Example 2:

// Input:
// s: "abab" p: "ab"

// Output:
// [0, 1, 2]

// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

// solution: sliding window

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
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

            if (!count) res.push_back(j);
        }

        return res;
    }
};