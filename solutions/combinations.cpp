// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
 

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n

// solution: dfs

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;

        function<void(int)> dfs = [&](int s) {
            if (s > n+1) return;
            else if (cur.size() == k) { 
                ans.push_back(cur); 
                return;
            }
            
            for (int i = s; i <= n; i++) {
                cur.push_back(i);
                dfs(i+1);
                cur.pop_back();
            }  
        };
    
        dfs(1);
        return ans;
    }
};