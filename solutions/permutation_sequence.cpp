// The set [1,2,3,...,n] contains a total of n! unique permutations.

// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

// "123"
// "132"
// "213"
// "231"
// "312"
// "321"
// Given n and k, return the kth permutation sequence.

// Note:

// Given n will be between 1 and 9 inclusive.
// Given k will be between 1 and n! inclusive.
// Example 1:

// Input: n = 3, k = 3
// Output: "213"
// Example 2:

// Input: n = 4, k = 9
// Output: "2314"

// solution: factorial

class Solution {
public:
    vector<int> fact, digits;

    void solve(string& ans, int n, int k) {
        if (n == 1) {
            ans += to_string(digits.back());
            return;
        }

        int index = k/fact[n-1];

        if ((k % fact[n-1]) == 0) index -= 1;
        
        ans += to_string(digits[index]);
        digits.erase(digits.begin()+index);
        k -= fact[n-1]*index;
        solve(ans, n-1, k);
    }

    string getPermutation(int n, int k) {
        int f = 1;
        fact.push_back(f);

        for (int i = 1; i < n; ++i) {
            f *= i;
            fact.push_back(f);
        }

        for (int i = 1; i <= n; ++i) digits.push_back(i);
        
        string ans = "";
        solve(ans, n, k);

        return ans;
    }
};