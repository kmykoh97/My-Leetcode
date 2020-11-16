// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

// Constraints:

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10

// solution: backtracking

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> hs;
        vector<vector<int>> ans;
        vector<int> cur;
        
        for (int x : nums) hs[x]++;

        backtrack(ans, hs, cur, nums.size());
        return ans;
    }
    
    void backtrack(vector<vector<int>>& ans, map<int, int>& hs, vector<int>& cur, int n) {
        if (n == cur.size()) ans.push_back(cur);
        
        for (auto it = hs.begin(); it != hs.end(); ++it) {
            if (it->second) {
                int x = it->first;
                cur.push_back(x);
                hs[x]--;
                backtrack(ans, hs, cur, n);
                hs[x]++;
                cur.pop_back();
            }
        }
    }
};