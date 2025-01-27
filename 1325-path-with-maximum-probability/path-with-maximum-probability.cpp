class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges,
                          vector<double>& succProb, int start_node,
                          int end_node) {
        vector<vector<pair<int, double>>> adj(n, vector<pair<int, double>>());
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> costArr(n, 0.0);
        costArr[start_node] = 1.0;
        queue<pair<int, double>> q;
        q.push({start_node, 1.0});
        while (q.size()) {
            auto i = q.front();
            int temp = i.first;
            double cost = i.second;
            q.pop();
             if(costArr[temp]>cost) continue;
            for (int i = 0; i < adj[temp].size(); i++) {
                int neighbor = adj[temp][i].first;
                double currCost = adj[temp][i].second;
                double totalCost = currCost * cost;
                if (costArr[neighbor] < totalCost) {
                    costArr[neighbor] = totalCost;
                    q.push({neighbor, totalCost});
                }
            }
        }
        return costArr[end_node];
    }
};