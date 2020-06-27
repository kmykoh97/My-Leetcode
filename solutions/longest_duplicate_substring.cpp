// Given a string S, consider all duplicated substrings: (contiguous) substrings of S that occur 2 or more times.  (The occurrences may overlap.)

// Return any duplicated substring that has the longest possible length.  (If S does not have a duplicated substring, the answer is "".)

 

// Example 1:

// Input: "banana"
// Output: "ana"
// Example 2:

// Input: "abcd"
// Output: ""
 

// Note:

// 2 <= S.length <= 10^5
// S consists of lowercase English letters.

// solution: binary search & rolling hash & sliding window

class Solution {
public:
    vector<int> roll;

    bool match(string s, int len, int size, string& ans) {
        unordered_map<int, vector<int>> m;
        int hash = 0;

        for (int i = 0; i < size; ++i) hash = (hash*26 + (s[i]-'a')) % 10000007;
        
        m[hash].push_back(0);

        for (int j = size; j < len; ++j) {
            hash = ((hash-roll[size-1]*(s[j-size]-'a')) % 10000007 + 10000007) % 10000007;
            hash = (hash*26 + (s[j]-'a')) % 10000007;

            if (m.find(hash) != m.end()) {
                for (auto start : m[hash]) {
                    string temp = s.substr(start, size);
                    string curr = s.substr(j-size+1, size);

                    if (temp.compare(curr) == 0) {
                        ans = temp;
                        return true;
                    }
                }
            }

            m[hash].push_back(j-size+1);
        }
        
        return false;
    }

    string longestDupSubstring(string S) {
        if (S.size() == 0) return "";
        
        int low = 1, high = S.size(), mid;
        string ans = "", temp;
        roll.resize(S.size());
        roll[0] = 1;

        for (int i = 1; i < S.size(); ++i) roll[i] = (26*roll[i-1]) % 10000007;
        
        while (low <= high) {
            temp = "";
            mid = low+(high-low)/2;
            
            if (match(S, S.size(), mid, temp)) {
                if (temp.size() > ans.size()) ans = temp;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return ans;
    }
};