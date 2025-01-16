class Solution {
public:
    bool dfs(vector<vector<int>> &adjList, int current, int destination, vector<bool> &isVisited) {
        // If we reach the destination, return true
        if (current == destination) return true;

        // Mark the current node as visited
        isVisited[current] = true;

        // Explore all neighbors
        for (int neighbor : adjList[current]) {
            if (!isVisited[neighbor]) {
                if (dfs(adjList, neighbor, destination, isVisited)) {
                    return true; // If destination is found in any path, return true
                }
            }
        }

        return false; // Return false if no path leads to the destination
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Build adjacency list
        vector<vector<int>> adjList(n);
        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        // Initialize visited vector
        vector<bool> isVisited(n, false);

        // Call DFS from the source
        return dfs(adjList, source, destination, isVisited);
    }
};
