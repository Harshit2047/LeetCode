class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

       
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

       
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> temp = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while (!pq.empty()) {
            vector<int> xd = pq.top();
            pq.pop();

            int diff = xd[0];
            int x = xd[1];
            int y = xd[2];

           
            if (x == n - 1 && y == m - 1) return diff;

            for (int i = 0; i < temp.size(); i++) {
                int x_ = x + temp[i][0];
                int y_ = y + temp[i][1];

                if (x_ >= 0 && y_ >= 0 && x_ < n && y_ < m) {
                    int effort = max(diff, abs(grid[x_][y_] - grid[x][y]));
                    if (effort < dist[x_][y_]) {
                        dist[x_][y_] = effort;
                        pq.push({effort, x_, y_});
                    }
                }
            }
        }

        return -1; 
    }
};
