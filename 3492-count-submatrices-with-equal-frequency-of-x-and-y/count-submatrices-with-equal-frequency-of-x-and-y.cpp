class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int count = 0;
        vector<vector<pair<int, int>>> adj(grid.size(), vector<pair<int, int>>(grid[0].size(), {0, 0}));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0) {
                    if (grid[i][j] == 'X') {
                        adj[i][j].first = (j > 0) ? adj[i][j-1].first + 1 : 1;
                        adj[i][j].second = (j > 0) ? adj[i][j-1].second : 0;
                    } else if (grid[i][j] == 'Y') {
                        adj[i][j].first = (j > 0) ? adj[i][j-1].first : 0;
                        adj[i][j].second = (j > 0) ? adj[i][j-1].second + 1 : 1;
                    } else {
                        adj[i][j].first = (j > 0) ? adj[i][j-1].first : 0;
                        adj[i][j].second = (j > 0) ? adj[i][j-1].second : 0;
                    }
                } else if (j == 0) {
                    if (grid[i][j] == 'X') {
                        adj[i][j].first = (i > 0) ? adj[i-1][j].first + 1 : 1;
                        adj[i][j].second = (i > 0) ? adj[i-1][j].second : 0;
                    } else if (grid[i][j] == 'Y') {
                        adj[i][j].first = (i > 0) ? adj[i-1][j].first : 0;
                        adj[i][j].second = (i > 0) ? adj[i-1][j].second + 1 : 1;
                    } else {
                        adj[i][j].first = (i > 0) ? adj[i-1][j].first : 0;
                        adj[i][j].second = (i > 0) ? adj[i-1][j].second : 0;
                    }
                } else {
                    if (grid[i][j] == 'X') {
                        adj[i][j].first = adj[i][j-1].first + 1 + adj[i-1][j].first - adj[i-1][j-1].first;
                        adj[i][j].second = adj[i][j-1].second + adj[i-1][j].second - adj[i-1][j-1].second;
                    } else if (grid[i][j] == 'Y') {
                        adj[i][j].first = adj[i][j-1].first + adj[i-1][j].first - adj[i-1][j-1].first;
                        adj[i][j].second = adj[i][j-1].second + 1 + adj[i-1][j].second - adj[i-1][j-1].second;
                    } else {
                        adj[i][j].first = adj[i][j-1].first + adj[i-1][j].first - adj[i-1][j-1].first;
                        adj[i][j].second = adj[i][j-1].second + adj[i-1][j].second - adj[i-1][j-1].second;
                    }
                }
                if (adj[i][j].first == adj[i][j].second && adj[i][j].first!=0 ) count++;
            }
        }
        return count;
    }
};
