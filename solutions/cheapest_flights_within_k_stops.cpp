// There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

// Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

// Example 1:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 1
// Output: 200
// Explanation: 
// The graph looks like this:


// The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
// Example 2:
// Input: 
// n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
// src = 0, dst = 2, k = 0
// Output: 500
// Explanation: 
// The graph looks like this:


// The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

// Constraints:

// The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
// The size of flights will be in range [0, n * (n - 1) / 2].
// The format of each flight will be (src, dst, price).
// The price of each flight will be in the range [1, 10000].
// k is in the range of [0, n - 1].
// There will not be any duplicated flights or self cycles.

// solution: dijkstra algorithm or BFS or DFS+pruning

class Solution {
public:
    static void solve(vector<vector<int>>& adj, vector<vector<int>>& cost, int src, int dst, int k, int& fare, int totalCost, vector<bool>& visited) {
        if (k < -1) return;

        if (src == dst) {
            fare = min(fare, totalCost);
            return;
        }
    
        visited[src] = true;

        for (int i = 0; i < adj[src].size(); i++) {
            if (!visited[adj[src][i]] && (totalCost+cost[src][adj[src][i]] <= fare)) {
                solve(adj, cost, adj[src][i], dst, k-1, fare, totalCost+cost[src][adj[src][i]], visited);
            }
        }
        
        visited[src] = false;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<int>> adj(n);
        vector<vector<int>> cost(n+1, vector<int>(n+1));
        
        for (int i = 0; i < flights.size(); i++) {    
            adj[flights[i][0]].push_back(flights[i][1]);
            cost[flights[i][0]][flights[i][1]] = flights[i][2];
        }
        
        vector<bool> visited(n+1, false); // for pruning
        int fare = INT_MAX;
        solve(adj, cost, src, dst, K, fare, 0, visited);
        
        if (fare==INT_MAX) return -1;
        else return fare;
    }
};