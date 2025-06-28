class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int color) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 1;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = color;
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        while (q.size()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < dir.size(); i++) {
                int x_ = x + dir[i][0];
                int y_ = y + dir[i][1];
                if (x_ >= 0 && y_ >= 0 && x_ < n && y_ < m &&
                    grid[x_][y_] == 1) {
                    count++;
                    grid[x_][y_] = color;
                    q.push({x_, y_});
                }
            }
        }
        return count;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int color = 2;
        int n = grid.size();
        int m = grid[0].size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int count = helper(grid, i, j, color);
                    mp[color] = count;
                    color++;
                }
            }
        }
        int Finalans = 0;
        vector<vector<int>> temp = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> st;
                    int ans = 1;
                    for (int k = 0; k < temp.size(); k++) {
                        int x_ = i + temp[k][0];
                        int y_ = j + temp[k][1];
                        if (x_ >= 0 && y_ >= 0 && x_ < n && y_ < m) {
                            int color = grid[x_][y_];
                            if (st.find(color) == st.end()) {
                                
                                int count = mp[color];
                                ans += count;
                                st.insert(color);
                            }
                        }
                    }
                    Finalans = max(Finalans, ans);
                }
            }
        }
        if (Finalans == 0) {
            for (auto i : mp) {
                Finalans = max(Finalans, i.second);
            }
        }
        return Finalans;
    }
};