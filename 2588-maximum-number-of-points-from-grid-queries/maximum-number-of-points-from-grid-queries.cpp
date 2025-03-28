class Solution {
public:
    
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int totalCells = m * n;
        vector<int> ans(queries.size());
        
        // Min-heap (priority queue) for BFS traversal (sorted by grid values)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        
        // Directions for 4-way movement
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Visited array
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Sort queries along with original indices
        vector<pair<int, int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++) {
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());

        // Start BFS from the top-left corner
        pq.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int count = 0, lastQueryValue = 0;

        for (auto& [query, index] : sortedQueries) {
            // Expand reachable cells while grid values < query value
            while (!pq.empty() && pq.top().first < query) {
                auto [val, cell] = pq.top();
                pq.pop();
                int x = cell.first, y = cell.second;
                count++;  // We can reach this cell
                
                // Explore adjacent cells
                for (auto& [dx, dy] : dir) {
                    int nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        pq.push({grid[nx][ny], {nx, ny}});
                    }
                }
            }
            ans[index] = count;  // Store result for this query
        }
        return ans;
    }
};
