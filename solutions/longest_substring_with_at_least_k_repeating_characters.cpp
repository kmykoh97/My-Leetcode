// Given a string s and an integer k, return the length of the longest substring of s such that the frequency of each character in this substring is less than or equal to k.

 

// Example 1:

// Input: s = "aaabb", k = 3
// Output: 3
// Explanation: The longest substring is "aaa", as 'a' is repeated 3 times.
// Example 2:

// Input: s = "ababbc", k = 2
// Output: 5
// Explanation: The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.
 

// Constraints:

// 1 <= s.length <= 104
// s consists of only lowercase English letters.
// 1 <= k <= 105

// solution: sliding window, recursion

class Solution {
public:
    int longestSubstring(string s, int k) {
        int len = s.length();
        map<char, int> m;
        int ans = 0;
        vector<int> pos;
        pos.push_back(-1);

        if (len == 0 || len < k) return 0;
        
        for (int i = 0; i < len; i++) m[s[i]]++;

        for (int i = 0; i < len; i++) {
            if (m[s[i]] < k) pos.push_back(i);
        }

        pos.push_back(len);
        
        if (pos.size() == 2) return len;
        
        for (int i = 0; i < pos.size() - 1; i++) {
            if (pos[i]+1 != pos[i+1]) {
                ans = max(ans, longestSubstring(s.substr(pos[i]+1, pos[i+1]-pos[i]-1), k));
            }
        }
        
        return ans;
    }
};