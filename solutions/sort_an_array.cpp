// Given an array of integers nums, sort the array in ascending order.

 

// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Example 2:

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
 

// Constraints:

// 1 <= nums.length <= 50000
// -50000 <= nums[i] <= 50000

// solution: quicksort

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quicksort(nums, 0, nums.size()-1);
        return nums;
    }

    void quicksort(vector<int>& nums, int start, int end) {
        if (start < end) {
            int mid = partition(nums, start, end);
            quicksort(nums, start, mid-1);
            quicksort(nums, mid+1, end);
        }
    }

    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[end];
        int initial = start;

        for (int i = start; i < end; i++) {
            if (nums[i] < pivot) {
                int temp = nums[i];
                nums[i] = nums[initial];
                nums[initial++] = temp;
            }
        }

        int temp = nums[initial];
        nums[initial] = nums[end];
        nums[end] = temp;
        
        return initial;
    }
};