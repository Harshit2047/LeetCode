class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &i : meetings) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }

        const int INF = 1e9;
        vector<int> dist(n, INF);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        dist[0] = 0;
        dist[firstPerson] = 0;
        q.push({0, 0});
        q.push({0, firstPerson});

        while (!q.empty()) {
            auto [curTime, idx] = q.top(); 
            q.pop();

            // Skip if this is not the best known time
            if (curTime > dist[idx]) continue;

            for (auto &p : adj[idx]) {
                int neighbor = p.first;
                int Time = p.second;
                if (Time >= curTime && Time < dist[neighbor]) {
                    dist[neighbor] = Time;
                    q.push({Time, neighbor});
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dist[i] != INF) ans.push_back(i);
        }
        return ans;
    }
};
