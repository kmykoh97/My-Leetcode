// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
// Example 2:

// Input: n = 1
// Output: ["()"]
 

// Constraints:

// 1 <= n <= 8

// solution: dfs

class Solution {
public:
    vector<string> ans;

    void dfs(int left, int right, string& s) {
        if (left+right == 0) {
            ans.push_back(s);
            return;
        }

        if (left > right) return;
        if (left > 0) {
            s += '(';
            dfs(left-1, right, s);
            s.pop_back();
        }
        if (right > 0) {
            s += ')';
            dfs(left, right-1, s);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        dfs(n, n, s);

        return ans;
    }
};