class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
         const int MOD = 1e9 + 7;
        
        // Adjacency list representation
        vector<vector<pair<int, int>>> graph(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }

        // Min-heap for Dijkstra (time, node)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0}); // Start from node 0

        // Distance and ways arrays
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            if (currTime > dist[node]) continue; // Skip outdated entries

            for (auto& [neighbor, time] : graph[node]) {
                long long newTime = currTime + time;
                
                if (newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                    ways[neighbor] = ways[node];  // Reset count for new shortest path
                } 
                else if (newTime == dist[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD; // Accumulate paths
                }
            }
        }

        return ways[n - 1];

    }
};