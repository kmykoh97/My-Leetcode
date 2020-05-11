#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
// An empty string is also valid.
// Example 1:
// Input: "()"
// Output: True
// Example 2:
// Input: "(*)"
// Output: True
// Example 3:
// Input: "(*))"
// Output: True
// Note:
// The string size will be in the range [1, 100].

// solution: dp or greedy or 2 stacks

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> hi, lo;

        // take care of ')', keep '(' and '*' in stack
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                hi.push(i);
                continue;
            }

            if (s[i] == ')') {
                if (!hi.empty()) {
                    hi.pop();
                    continue;
                } else if (!lo.empty()) {
                    if (lo.top() > i) {
                        return false;
                    }

                    lo.pop();
                    continue;
                } else {
                    return false;
                }
            }

            if (s[i] == '*') {
                lo.push(i);
                continue;
            }
        }

        // take care of '('
        while (!hi.empty()) {
            if (lo.empty()) {
                return false; // not enough * to balance
            }

            int temphi = hi.top();
            hi.pop();
            int templo = lo.top();
            lo.pop();

            if (templo < temphi) {
                return false;
            }
        }

        return true;
    }
};