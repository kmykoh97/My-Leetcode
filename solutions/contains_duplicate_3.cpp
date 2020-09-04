// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

// Example 1:

// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true
// Example 3:

// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false

// solution: 2 pointers

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        vector<pair<int, int>> data;
        
        for (int i = 0; i<n; i++) data.push_back(make_pair(nums[i], i));
        
        sort(data.begin(), data.end());
        int p1 = 0;
        int p2 = 1;
        
        while (p2 < n) {
	        long long int d1 = data[p1].first;
	        long long int d2 = data[p2].first;
            
	        if (abs(data[p1].second - data[p2].second) <= k && abs(d1-d2) <= t) return true;
	        if (abs(data[p1].second - data[p2].second) > k) p2++;
	        if (abs(d1 - d2) > t) p1++;
	        if (p1 == p2) p2++;
        }
        
        return false;
    }
};