// Given the coordinates of four points in 2D space, return whether the four points could construct a square.

// The coordinate (x,y) of a point is represented by an integer array with two integers.

// Example:

// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
// Output: True
 

// Note:

// All the input integers are in the range [-10000, 10000].
// A valid square has four equal sides with positive length and four equal angles (90-degree angles).
// Input points have no order.

// solution: math

class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2) {
        return sqrt((p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]));
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<double> lengths;
        
        for (int i = 0; i < 4; i++) {
            for (int j = i+1; j < 4; j++) {
                double curr = dist(points[i], points[j]);

                if (curr != 0) lengths.insert(curr);
                else return false;
            }
        }
        
        return (lengths.size() == 2);
    }
};