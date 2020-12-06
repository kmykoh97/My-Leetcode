// Given a string s, partition s such that every substring of the partition is a palindrome.

// Return all possible palindrome partitioning of s.

// Example:

// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]

// solution: dfs

class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }

        return true;
    }

    void dfs(int index, string s, vector<string>& current) {
        if (index == s.length()) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (!isPalindrome(s, index, i)) continue;
            current.push_back(s.substr(index, i-index+1));
            dfs(i+1, s, current);
            current.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> current;
        dfs(0, s, current);
        return ans;
    }
};