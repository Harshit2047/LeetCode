class Solution {
public:
    vector<vector<int>> dir{{2,-1},{2,1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};
    vector<vector<vector<double>>> dp; // Memoization table

    double helper(int n, int k, int row, int col) {
        if (row < 0 || col < 0 || row >= n || col >= n) return 0.0; // Out of bounds
        if (k == 0) return 1.0; // Base case: still on board after 0 moves
        if (dp[k][row][col] != -1.0) return dp[k][row][col];

        double prob = 0.0;
        for (auto &d : dir) {
            prob += 1.0/8.0 * helper(n, k - 1, row + d[0], col + d[1]);
        }
        return dp[k][row][col] = prob;
    }

    double knightProbability(int n, int k, int row, int column) {
        dp.assign(k + 1, vector<vector<double>>(n, vector<double>(n, -1.0))); 
        return helper(n, k, row, column);
    }
};