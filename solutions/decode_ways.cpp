// A message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.

// Example 1:

// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
// Example 2:

// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

// solution: dp

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1, 0);
        dp[0] = 1;
        
        if (s[0] == '0') dp[1] = 0;
        else dp[1] = 1;

        for (int i = 2; i <= s.length(); i++) {
            if (s[i-1] > '0') dp[i] += dp[i-1];
            if ((s[i-1] <= '6' && s[i-2] <= '2' && s[i-2] != '0') || s[i-2] == '1') dp[i] += dp[i-2];
        }

        return dp[s.length()];
    }
};