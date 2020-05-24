// Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

// Note: You may not slant the container and n is at least 2.

 
// image from https://leetcode.com/problems/container-with-most-water/


// The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

 

// Example:

// Input: [1,8,6,2,5,4,8,3,7]
// Output: 49

// solution: 2 pointers

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0, low = 0, high = height.size()-1;

        while (low < high) {
            int minheight = min(height[low], height[high]);
            maxarea = max(maxarea, minheight*(high-low));

            if (height[low] < height[high]) {
                low++;
            } else if (height[low] > height[high]) {
                high--;
            } else {
                low++;
                high--;
            }
        }

        return maxarea;
    }
};