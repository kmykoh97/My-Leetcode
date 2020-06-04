// Given a collection of intervals, merge all overlapping intervals.

// Example 1:

// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
// NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

// solution: sorting or hashmap

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itv) {
        vector<vector<int>> res;

        if (itv.size() == 0) return res;

        sort(itv.begin(), itv.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
        res.push_back(itv[0]);

        for (auto e : itv) {
            if (e[0] > res.back()[1]) {
                res.push_back(e);
            } else {
                res.back()[1] = max(e[1], res.back()[1]);
            }
        }

        return res;
    }
};