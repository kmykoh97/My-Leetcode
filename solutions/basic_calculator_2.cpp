// Implement a basic calculator to evaluate a simple expression string.

// The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

// Example 1:

// Input: "3+2*2"
// Output: 7
// Example 2:

// Input: " 3/2 "
// Output: 1
// Example 3:

// Input: " 3+5 / 2 "
// Output: 5
// Note:

// You may assume that the given expression is always valid.
// Do not use the eval built-in library function.

// solution: stack

class Solution {
public:
    int calculate(string s) {
        char sign = '+';
        int val = 0, ans = 0;
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) val = val*10+(c-'0');

            if (c == '+' || c == '-' || c == '*' || c == '/' || i == s.size()-1) {
                if (sign == '+') st.push(val);
                if (sign == '-') st.push(-1*val);
                if (sign == '*') {
                    int last = st.top();
                    st.pop();
                    st.push(last*val);
                }
                if (sign == '/') {
                    int last = st.top();
                    st.pop();
                    st.push(last/val);
                }

                sign = c;
                val = 0;
            }
        }

        while (!st.empty()) {
            int temp = st.top();
            st.pop();
            ans += temp;
        }

        return ans;
    }
};