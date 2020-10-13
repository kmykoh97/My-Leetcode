// Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

// Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

 

// Example 1:

// Input: s = "bcabc"
// Output: "abc"
// Example 2:

// Input: s = "cbacdcbc"
// Output: "acdb"
 

// Constraints:

// 1 <= s.length <= 104
// s consists of lowercase English letters.

// solution: greedy

class Solution {
public:
    string removeDuplicateLetters(string s) {
        uint16_t last[26];
        for (int i = 0; i < s.length(); ++i) last[s[i] - 'a'] = i;
        uint32_t seen = 0;
        
        string ans;
        for (int i = 0; i < s.length(); ++i)  {
            if (seen & (1 << s[i] - 'a')) continue;
            while (!ans.empty() && s[i] < ans.back() && i < last[ans.back() - 'a']) {
                seen &= ~(1 << ans.back() - 'a');
                ans.pop_back();
            }
            seen |= 1 << s[i] - 'a';
            ans.push_back(s[i]);
        }
        
        return ans;
    }
};