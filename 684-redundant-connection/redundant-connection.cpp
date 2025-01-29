class Solution {

public:
    vector<int> size;  
    vector<int> parent; 

    int find(int a) {  
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    void unionSets(int u, int v) {  
        int leaderA = find(u);
        int leaderB = find(v);

        if (leaderA != leaderB) {  
            if (size[leaderA] > size[leaderB]) {
                parent[leaderB] = leaderA;
                size[leaderA] += size[leaderB];
            } else {
                parent[leaderA] = leaderB;
                size[leaderB] += size[leaderA];
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);  
        size.resize(n + 1, 1); 

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto i : edges) {
            int u = i[0];
            int v = i[1];

            if (find(u) == find(v)) {
                return {u, v};
            } else {
                unionSets(u, v); 
            }
        }
        return {};
    }
};
