// There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

// Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

// Example 1:

// Input: 
// [[1,1,0],
//  [1,1,0],
//  [0,0,1]]
// Output: 2
// Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
// The 2nd student himself is in a friend circle. So return 2.
 

// Example 2:

// Input: 
// [[1,1,0],
//  [1,1,1],
//  [0,1,1]]
// Output: 1
// Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
// so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.

 

// Constraints:

// 1 <= N <= 200
// M[i][i] == 1
// M[i][j] == M[j][i]

// solution: dfs

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<bool> inCircle = vector(M.size(), false);
        int numCircles = 0;
        
        for (int i = 0; i < M.size(); i++) {
            if (inCircle[i]) continue;
            
            inCircle[i] == true;
            numCircles++;
            dfs(i, M, inCircle);
        }
        
        return numCircles;
    }
    
    void dfs(int studentIndex, vector<vector<int>>& M, vector<bool>& inCircle) {
        for (int i = 0; i < M.size(); i++) {
            if (inCircle[i]) continue;
            
            if (M[studentIndex][i] == 1) {
                inCircle[i] = true;
                dfs(i, M, inCircle);
            }
        }
    }
};