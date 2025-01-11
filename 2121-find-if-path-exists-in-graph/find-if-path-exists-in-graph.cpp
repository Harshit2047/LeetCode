class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Create an adjacency list
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // BFS to check if there's a path
        vector<bool> isVisited(n, false);
        queue<int> q;
        q.push(source);
        isVisited[source] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (current == destination) return true;

            for (int neighbor : adjList[current]) {
                if (!isVisited[neighbor]) {
                    isVisited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};
