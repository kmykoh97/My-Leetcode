// Given two strings s and t , write a function to determine if t is an anagram of s.

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
// Note:
// You may assume the string contains only lowercase alphabets.

// Follow up:
// What if the inputs contain unicode characters? How would you adapt your solution to such case?

// solution: map

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        unordered_map<char, int> hashmap;
        
        for (int i = 0; i < s.length(); i++) {
            hashmap[s[i]]++;
        }
        
        for (int j = 0; j < t.length(); j++) {
            hashmap[t[j]]--;
            
            if (hashmap[t[j]] < 0) {
                return false;
            }
        }
        
        return true;
    }
};