// Given a non-empty array of integers, return the k most frequent elements.

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
// Note:

// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
// It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
// You can return the answer in any order.

// solution: pq & map

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> elementFreq;
        vector<int> result;

        for (auto num : nums) {
            elementFreq[num]++;
        }
        
        typedef pair<int, int> P;        
        priority_queue<P, vector<P>, greater<P>> pq;
        int count = 0;

        for (auto iter : elementFreq) {
            if (count == k) {
                if (iter.second > pq.top().first) {
                    pq.pop();
                    pq.push({iter.second, iter.first});
                } 
            } else {
                pq.push({iter.second, iter.first});
                ++count;
            }
        }

        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;        
    }
};