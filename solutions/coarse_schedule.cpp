// There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

 

// Example 1:

// Input: numCourses = 2, prerequisites = [[1,0]]
// Output: true
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0. So it is possible.
// Example 2:

// Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
// Output: false
// Explanation: There are a total of 2 courses to take. 
//              To take course 1 you should have finished course 0, and to take course 0 you should
//              also have finished course 1. So it is impossible.
 

// Constraints:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
// 1 <= numCourses <= 10^5

// solution: dfs

class Solution {
public:
    static bool dfs(vector<int>& visited, vector<vector<int>>& dfsv, int i) {
        if (visited[i] == 2) return false;
        if (visited[i] == 1) return true;

        visited[i] = 2;

        for (int i : dfsv[i]) {
            if (!dfs(visited, dfsv, i)) return false; 
        }

        visited[i] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> dfsv(numCourses);
        vector<int> visited(numCourses, 0); // 0 : init, 1 : visited, 2 : visiting

        for (vector<int> p : prerequisites) {
            dfsv[p[0]].push_back(p[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(visited, dfsv, i)) return false;
        }

        return true;
    }
};