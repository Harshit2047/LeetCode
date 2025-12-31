class Solution {
public:
    vector<vector<int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};

    bool bfs(vector<vector<int>> &matrix, int r, int c) {
        queue<pair<int,int>> q;
        q.push({r, c});
        matrix[r][c] = 1;

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if (row == matrix.size() - 1) return true;

            for (auto &d : dir) {
                int x = row + d[0];
                int y = col + d[1];
                if (x >= 0 && x < matrix.size() &&
                    y >= 0 && y < matrix[0].size() &&
                    matrix[x][y] == 0) {
                    matrix[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<int>> &base, int idx, vector<vector<int>> &cells) {
        vector<vector<int>> matrix = base;

        for (int i = 0; i <= idx; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            matrix[x][y] = 1;
        }

        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                if (bfs(matrix, 0, j)) return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> matrix(row, vector<int>(col, 0));

        int low = 0, high = cells.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (helper(matrix, mid, cells)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans + 1;
    }
};
