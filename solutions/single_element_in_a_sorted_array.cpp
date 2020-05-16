#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

// Example 1:

// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:

// Input: [3,3,7,7,10,11,11]
// Output: 10
 

// Note: Your solution should run in O(log n) time and O(1) space.

// solution: map/set/binary search

// set solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        set<int> s;
        
        for (int num : nums) {
            if (s.count(num) == 1) {
                s.erase(num);
            } else {
                s.insert(num);
            }
        }

        for (int i : s) {
            return i;
        }
        
        return 0; // control shouldn't reach here
    }
};

// binary search solution
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size()-1;

        while (low < high) {
            int mid = (low+high)/2;

            if (nums[mid] == nums[mid+1]) {
                if ((high-mid)%2 == 0) {
                    low = mid + 2;
                } else {
                    high = mid - 1;
                }
            } else if (nums[mid] == nums[mid-1]) {
                if ((high-mid)%2 == 0) {
                    high = mid - 2;
                } else {
                    low = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }

        return nums[low];
    }
};