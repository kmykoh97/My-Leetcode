// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

 

// Example 1:

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: 
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]
// Example 2:

// Input: candidates = [2,5,2,1,2], target = 5
// Output: 
// [
// [1,2,2],
// [5]
// ]
 

// Constraints:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30

// solution: dfs

class Solution {
public:
    set<vector<int>> ans;

    void dfs(vector<int>& candidates, vector<int>& current, int index, int target) {
        if (target < 0 || index > candidates.size()) return;
        else if (target == 0) {
            ans.insert(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (candidates[i] < 0) continue;

            current.push_back(candidates[i]);
            dfs(candidates, current, i+1, target-candidates[i]);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, current, 0, target);

        for (vector<int> e : ans) {
            result.push_back(e);
        }

        return result;
    }
};