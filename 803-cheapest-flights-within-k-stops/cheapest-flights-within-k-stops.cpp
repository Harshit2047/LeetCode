class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Build the graph
        vector<pair<int, int>> adj[n];
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // Min-heap: (cost, node, stops)
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({0, src, 0});

        // Use a 2D visited: min cost to reach (node, stops)
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top(); pq.pop();

            if (u == dst) return cost;
            if (stops > k) continue;

            for (auto [v, price] : adj[u]) {
                if (cost + price < dist[v][stops + 1]) {
                    dist[v][stops + 1] = cost + price;
                    pq.push({cost + price, v, stops + 1});
                }
            }
        }

        return -1;
    }
};
