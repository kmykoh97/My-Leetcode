// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
 

// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.

// solution: 2 pointers

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size(), i = 0, j = n-1, k = n-1;
        vector<int> res(n);

	    while (i <= j) {
		    int v1 = nums[i]*nums[i];
		    int v2 = nums[j]*nums[j];

		    if (v1 > v2) {
			    res[k] = v1;
			    i++;
		    } else {
			    res[k] = v2;
			    j--;
		    }
            
		    k--;
	    }
	    
        return res;
    }
};