#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

// Example 1:

// Input: S = "ab#c", T = "ad#c"
// Output: true
// Explanation: Both S and T become "ac".
// Example 2:

// Input: S = "ab##", T = "c#d#"
// Output: true
// Explanation: Both S and T become "".
// Example 3:

// Input: S = "a##c", T = "#a#c"
// Output: true
// Explanation: Both S and T become "c".
// Example 4:

// Input: S = "a#c", T = "b"
// Output: false
// Explanation: S becomes "c" while T becomes "b".
// Note:

// 1 <= S.length <= 200
// 1 <= T.length <= 200
// S and T only contain lowercase letters and '#' characters.
// Follow up:

// Can you solve it in O(N) time and O(1) space?

// solution: iterative or stack(S(n)) or 2 pointers from end(S(1))

class Solution {
public:
    static string buildString(string str) {
        for (unsigned long i = 0; i < str.size(); i++) {
            if (str[i] == '#') {
                str.erase(i, 1);

                if (i != 0) {
                    str.erase(i-1, 1);
                    i--;
                }

                i--;
            }
        }

        return str;
    }

    bool backspaceCompare(string S, string T) {
        return (buildString(S) == buildString(T));
    }
};