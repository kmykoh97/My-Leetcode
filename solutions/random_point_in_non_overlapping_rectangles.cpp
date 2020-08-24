// Given a list of non-overlapping axis-aligned rectangles rects, write a function pick which randomly and uniformily picks an integer point in the space covered by the rectangles.

// Note:

// An integer point is a point that has integer coordinates. 
// A point on the perimeter of a rectangle is included in the space covered by the rectangles. 
// ith rectangle = rects[i] = [x1,y1,x2,y2], where [x1, y1] are the integer coordinates of the bottom-left corner, and [x2, y2] are the integer coordinates of the top-right corner.
// length and width of each rectangle does not exceed 2000.
// 1 <= rects.length <= 100
// pick return a point as an array of integer coordinates [p_x, p_y]
// pick is called at most 10000 times.
// Example 1:

// Input: 
// ["Solution","pick","pick","pick"]
// [[[[1,1,5,5]]],[],[],[]]
// Output: 
// [null,[4,1],[4,1],[3,3]]
// Example 2:

// Input: 
// ["Solution","pick","pick","pick","pick","pick"]
// [[[[-2,-2,-1,-1],[1,0,3,0]]],[],[],[],[],[]]
// Output: 
// [null,[-1,-2],[2,0],[-2,-1],[3,0],[-2,-2]]
// Explanation of Input Syntax:

// The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array of rectangles rects. pick has no arguments. Arguments are always wrapped with a list, even if there aren't any.

// solution: random

class Solution {
public:
    int num_pts;
    vector<int> rect_cum_count;
    vector<vector<int>> rects;

    Solution(vector<vector<int>>& rects) {
        num_pts = 0;
        this->rects = rects;

        for (vector<int>& rect: rects) {
            num_pts += (rect[2] - rect[0] + 1)*(rect[3] - rect[1] + 1);
            rect_cum_count.push_back(num_pts);
        }
    }
    
    vector<int> pick() {
        int pt_idx = rand() % num_pts;
        int l = 0, r = rects.size()-1;

        while (l < r) {
            int mid = l + (r-l)/2;

            if (rect_cum_count[mid] <= pt_idx) l = mid+1;
            else r = mid;
        }

        vector<int>& rect = rects[l];
        int x_pts = rect[2] - rect[0] + 1;
        int y_pts = rect[3] - rect[1] + 1;
        int pts_in_rect = x_pts*y_pts;
        int pt_start = rect_cum_count[l] - pts_in_rect;
        int offset = pt_idx - pt_start;

        return {rect[0] + offset%x_pts, rect[1] + offset/x_pts};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */