// Consider a directed graph, with nodes labelled 0, 1, ..., n-1.  In this graph, each edge is either red or blue, and there could be self-edges or parallel edges.

// Each [i, j] in red_edges denotes a red directed edge from node i to node j.  Similarly, each [i, j] in blue_edges denotes a blue directed edge from node i to node j.

// Return an array answer of length n, where each answer[X] is the length of the shortest path from node 0 to node X such that the edge colors alternate along the path (or -1 if such a path doesn't exist).

 

// Example 1:

// Input: n = 3, red_edges = [[0,1],[1,2]], blue_edges = []
// Output: [0,1,-1]
// Example 2:

// Input: n = 3, red_edges = [[0,1]], blue_edges = [[2,1]]
// Output: [0,1,-1]
// Example 3:

// Input: n = 3, red_edges = [[1,0]], blue_edges = [[2,1]]
// Output: [0,-1,-1]
// Example 4:

// Input: n = 3, red_edges = [[0,1]], blue_edges = [[1,2]]
// Output: [0,1,2]
// Example 5:

// Input: n = 3, red_edges = [[0,1],[0,2]], blue_edges = [[1,0]]
// Output: [0,1,1]
 

// Constraints:

// 1 <= n <= 100
// red_edges.length <= 400
// blue_edges.length <= 400
// red_edges[i].length == blue_edges[i].length == 2
// 0 <= red_edges[i][j], blue_edges[i][j] < n

// solution: bfs

class Solution {
public:
    unordered_map<int, vector<int>> redmap;
    unordered_map<int, vector<int>> bluemap;

    void buildgraph(vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        for (vector<int> edges : red_edges) {
            redmap[edges[0]].push_back(edges[1]);
        }

        for (vector<int> edges : blue_edges) {
            bluemap[edges[0]].push_back(edges[1]);
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        buildgraph(red_edges, blue_edges);
        unordered_set<int> redseen;
        unordered_set<int> blueseen;
        queue<pair<int, int>> q; // node, color pair
        vector<int> ans(n, -1);
        int steps = 0;

        q.push({0, 0});
        q.push({0, 1});
        redseen.insert(0);
        blueseen.insert(0);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int node = q.front().first;
                int color = q.front().second; // 0 for red, 1 for blue
                q.pop();
                if (ans[node] < 0) ans[node] = steps;
                unordered_map<int, vector<int>>& rbedges = color ? bluemap : redmap;
                auto& seen = color? blueseen : redseen;
                
                for (int adjacentnodes : rbedges[node]) {
                    if (seen.count(adjacentnodes)) continue;
                    seen.insert(adjacentnodes);
                    q.push({adjacentnodes, 1-color});
                }
            }

            steps++;
        }

        return ans;
    }
};