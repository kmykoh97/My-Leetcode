// Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.

// Return a list of all possible strings we could create. You can return the output in any order.

 

// Example 1:

// Input: S = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]
// Example 2:

// Input: S = "3z4"
// Output: ["3z4","3Z4"]
// Example 3:

// Input: S = "12345"
// Output: ["12345"]
// Example 4:

// Input: S = "0"
// Output: ["0"]
 

// Constraints:

// S will be a string with length between 1 and 12.
// S will consist only of letters or digits.

// solution: dfs

class Solution {
public:
    set<string> ans;

    void dfs(string s, string current, int i) {
        if (i == s.length()) {
            ans.insert(current);
            return;
        }

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            string current1 = current;
            string current2 = current;
            current1 += toupper(s[i]);
            current2 += tolower(s[i]);
            dfs(s, current1, i+1);
            dfs(s, current2, i+1);
        } else {
            current += s[i];
            dfs(s, current, i+1);
        }
    }

    vector<string> letterCasePermutation(string S) {
        string current = "";
        vector<string> res;
        dfs(S, current, 0);

        for (string s : ans) {
            res.push_back(s);
        }

        return res;
    }
};