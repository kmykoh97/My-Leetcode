// There are a total of n courses you have to take, labeled from 0 to n-1.

// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

// Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

// There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

// Example 1:

// Input: 2, [[1,0]] 
// Output: [0,1]
// Explanation: There are a total of 2 courses to take. To take course 1 you should have finished   
//              course 0. So the correct course order is [0,1] .
// Example 2:

// Input: 4, [[1,0],[2,0],[3,1],[3,2]]
// Output: [0,1,2,3] or [0,2,1,3]
// Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both     
//              courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. 
//              So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
// Note:

// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.

// solution: dfs

class Solution {
public:
    vector<vector<int>> graph_;
    
    bool dfs(int cur, vector<int>& v, vector<int>& ans) {
        if (v[cur] == 1) return true;
        if (v[cur] == 2) return false;
        
        v[cur] = 1;
        
        for (const int t : graph_[cur]) {
            if (dfs(t, v, ans)) return true;
        }
        
        v[cur] = 2;
        ans.push_back(cur);
        
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph_ = vector<vector<int>>(numCourses);
        
        for (vector<int> p : prerequisites) {
            graph_[p[0]].push_back(p[1]);
        }
        
        vector<int> v(numCourses, 0);
        vector<int> ans;
        
        for (int i = 0; i < numCourses; ++i) {
            if (dfs(i, v, ans)) return {};
        }
        
        return ans;
    }  
};