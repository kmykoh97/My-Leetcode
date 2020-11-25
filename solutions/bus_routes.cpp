// We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.

// We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.

// Example:
// Input: 
// routes = [[1, 2, 7], [3, 6, 7]]
// S = 1
// T = 6
// Output: 2
// Explanation: 
// The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
 

// Constraints:

// 1 <= routes.length <= 500.
// 1 <= routes[i].length <= 10^5.
// 0 <= routes[i][j] < 10 ^ 6.

// solution: bfs

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        map<int, vector<int>> stoptobus;
        vector<int> visited(routes.size(), 0);
        queue<int> q;
        q.push(S);
        int ans = 0;

        if (S == T) return 0;
        
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) stoptobus[stop].push_back(i);
        }

        while (!q.empty()) {
            int size = q.size();
            ans++;

            for (int i = 0; i < size; i++) {
                int stop = q.front();
                q.pop();

                for (int bus : stoptobus[stop]) {
                    if (visited[bus]) continue;
                    else visited[bus] = 1;

                    for (int route : routes[bus]) {
                        if (route == T) return ans; 
                        q.push(route);
                    }
                }
            }
        }

        return -1;
    }
};