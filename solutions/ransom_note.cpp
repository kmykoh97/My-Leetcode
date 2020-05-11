#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <set>

using namespace std;

// Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

// Each letter in the magazine string can only be used once in your ransom note.

 

// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true
 

// Constraints:

// You may assume that both strings contain only lowercase letters.

// solution: map

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> m;

        for (char c : magazine) {
            m[c]++;
        }

        for (char c : ransomNote) {
            if (m.count(c)) {
                if (m[c] == 0) {
                    return false;
                } else {
                    m[c]--;
                }
            } else {
                return false;
            }
        }

        return true;
    }
};