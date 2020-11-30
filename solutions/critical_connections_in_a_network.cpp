// There are n servers numbered from 0 to n-1 connected by undirected server-to-server connections forming a network where connections[i] = [a, b] represents a connection between servers a and b. Any server can reach any other server directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some server unable to reach some other server.

// Return all critical connections in the network in any order.

 

// Example 1:



// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.
 

// Constraints:

// 1 <= n <= 10^5
// n-1 <= connections.length <= 10^5
// connections[i][0] != connections[i][1]
// There are no repeated connections.

// solution: tarjan algorithm

class Solution {
public:
    void dfs(int index, vector<int> *adj, vector<bool> &visited, vector<int> &low, vector<int> &tp, int timer, vector<vector<int>> &answer, int parent) {
        visited[index] = true;
        low[index] = tp[index] = timer;

        for (int i : adj[index]) {
            if (i == parent) continue;
            if (visited[i]) {
                low[index] = min(low[index], tp[i]);
            } else {
                dfs(i, adj, visited, low, tp, timer+1, answer, index);
                low[index] = min(low[index], low[i]);

                if (low[i] > tp[index]) {
                    answer.push_back({index, i});
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> answer;
        vector<int> adj[n];

        for (int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }

        vector<bool> visited(n, false);
        vector<int> low(n, 0);
        vector<int> tp(n, 0);
        int timer = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(0, adj, visited, low, tp, timer, answer, -1);
        }
        
        return answer;
    }
};