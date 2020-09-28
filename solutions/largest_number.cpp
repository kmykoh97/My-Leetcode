// Given a list of non negative integers, arrange them such that they form the largest number.

// Example 1:

// Input: [10,2]
// Output: "210"
// Example 2:

// Input: [3,30,34,5,9]
// Output: "9534330"
// Note: The result may be very large, so you need to return a string instead of an integer.

// solution: comparator

class Solution {
public:
    static bool comparator(int &a, int &b) {
        string str1 = to_string(a);
        string str2 = to_string(b);
        string temp1 = str1+str2;
        string temp2 = str2+str1;

        return temp1 > temp2;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comparator);
        string ans = "";

        for (int num : nums) {
            ans += to_string(num);
        }

        if (ans[0] == '0') return "0";

        return ans;
    }
};