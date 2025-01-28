class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        int freshcount = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshcount++;
                }
            }
        }
        if (freshcount == 0)
            return 0;
        int ans = 0;
        while (q.size()) {
            int s = q.size();
            bool rooten = false;
            for (int ok = 0; ok < s; ok++) {
                auto temp = q.front();
                q.pop();
                int i = temp.first;
                int j = temp.second;
                for (int x = 0; x < dir.size(); x++) {
                    int i_ = i + dir[x][0];
                    int j_ = j + dir[x][1];
                    if ((i_ >= 0 && i_ < grid.size()) &&
                        (j_ >= 0 && j_ < grid[0].size())) {
                        if (grid[i_][j_] == 1) {
                            grid[i_][j_] = 2;
                            q.push({i_, j_});
                            rooten = true;
                            freshcount--;
                        }
                    }
                }
            }
            if (rooten == true)
                ans++;
        }
        return freshcount == 0 ? ans : -1;
    }
};