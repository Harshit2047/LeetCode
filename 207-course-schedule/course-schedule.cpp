class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<bool>& isVisited, int start,
             vector<bool>& path) {
        isVisited[start] = true;
        path[start] = true;
        for (int i = 0; i < adj[start].size(); i++) {
            int neighbor = adj[start][i];
            if (isVisited[neighbor] == false) {
                if (dfs(adj, isVisited, neighbor, path)) {
                    return true;
                }
            } else if (isVisited[neighbor] && path[neighbor])
                return true;
        }
        path[start] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> isVisited(n, false);
        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<bool> path(n, false);
        for (int i = 0; i < n; i++) {
            if (!isVisited[i]) {
                if (dfs(adj, isVisited, i, path)) {
                    return false;
                }
            }
        }
        return true;
    }
};