// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

// Example 1:

// Input: [1,3,4,2,2]
// Output: 2
// Example 2:

// Input: [3,1,3,4,2]
// Output: 3
// Note:

// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated more than once.

// solution: floyd cycle detection(2 pointers)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int index1 = nums[0];
        int index2 = nums[0];
        
        do {
            index1 = nums[index1];
            index2 = nums[nums[index2]];
        } while (index1 != index2);
        
        index1 = nums[0];
        
	    while (index2 != index1) {
		    index2 = nums[index2];
		    index1 = nums[index1];
	    }
                          
        return index1;
    }
};