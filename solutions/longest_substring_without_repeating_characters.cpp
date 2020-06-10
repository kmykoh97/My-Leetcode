// Given a string, find the length of the longest substring without repeating characters.

// Example 1:

// Input: "abcabcbb"
// Output: 3 
// Explanation: The answer is "abc", with the length of 3. 
// Example 2:

// Input: "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.
// Example 3:

// Input: "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3. 
//              Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

// solution: map or set

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        int maxcount = 1;
        int i = 0;
        int temppointer = 0;
        unordered_map<char, int> hashmap;
        
        while (i < s.length()) {
            if (hashmap.find(s[i]) != hashmap.end()) {
                if (temppointer > hashmap[s[i]]) {
                    maxcount = max(maxcount, i - temppointer + 1);
                } else {
                    temppointer = hashmap[s[i]] + 1;
                }

                hashmap[s[i]] = i;
                i++;
            } else {
                hashmap[s[i]] = i;
                maxcount = max(maxcount, i - temppointer + 1);
                i++;
            }
        }
        
        return maxcount;
    }
};