// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// Your algorithm should run in O(n) complexity.

// Example:

// Input: [100, 4, 200, 1, 3, 2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// solution: set

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> temp;
        int maxcount = 0;
        
        for (int i : nums) {
            temp.insert(i);
        }
        
        for (int i : nums) {
            if (temp.count(i-1) == 0) {
                int currentcount = 1;
                int currentnumber = i;
                
                while (temp.count(currentnumber+1)) {
                    currentnumber++;
                    currentcount++;
                }
                
                maxcount = max(maxcount, currentcount);
            }
        }
        
        return maxcount;
    }
};