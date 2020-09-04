// A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

 

// Example 1:

// Input: S = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.


// Note:

// S will have length in range [1, 500].
// S will consist of lowercase English letters ('a' to 'z') only.

// solution: greedy

class Solution {
public:
    vector<int> partitionLabels(string S) {
        // get the last position of each alphabet
        vector<int> lastpos(26, -1);

        for (int i = 0; i < S.length(); i++) {
            lastpos[S[i]-'a'] = i;
        }

        // next use modified sliding windows
        vector<int> ans;
        int minp = -1, plen = 0;

        if (!S.length()) return ans;

        for (int i = 0; i < S.length(); i++) {
            int lp = lastpos[S[i]-'a'];
            minp = max(minp, lp);
            ++plen;

            if (i == minp) {
                ans.push_back(plen);
                minp = -1;
                plen = 0;
            }
        }

        return ans;
    }
};