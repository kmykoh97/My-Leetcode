// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// Example:

// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
// Note:

// If there is no such window in S that covers all characters in T, return the empty string "".
// If there is such window, you are guaranteed that there will always be only one unique minimum window in S.

// solution: 

class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        if(t.size() == 0) return res;

        int count = size(t);
        unordered_map<char, bool> look_for; // if we have to look for a specific char
        unordered_map<char, int> find; // the number of chars that we still have to find

        // set up initial mapping
        for(int i = 0; i < size(t); i++){
            int cur_idx = t[i] - 'A';
            look_for[cur_idx] = true;
            find[cur_idx]++;
        }

        int rp = 0;
        for (int lp = 0; lp < s.size(); lp++){
            //find the smallest substring starting at lp that contains all characters we are looking for
            while (rp < s.size() && count > 0){ // the first left most element gets added automatically within this loop, if initial count > 0
                if (int cur_idx = s[rp] - 'A'; look_for.count(cur_idx)){
                    if (--find[cur_idx] >= 0) count--;
                }
                rp++;
            }
            if(count == 0){ //there is a valid substring starting at this left point
                if(rp- lp < res.size() || res == "") res = s.substr(lp, rp - lp);
            }
            // remove left most element
            if(int lp_idx = s[lp] - 'A'; look_for.count(lp_idx)){
                if(++find[lp_idx] > 0) count++;
            }
        }
        return res;
    }
};