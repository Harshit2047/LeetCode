class Solution {
public:
    int helper(vector<vector<int>> &grid, int i, int j1, int j2, vector<int> &v, vector<vector<vector<int>>> &dp){
        int n = grid.size(), m = grid[0].size();
        if(i == n - 1){
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
         if(dp[i][j1][j2]!=INT_MIN) return dp[i][j1][j2];
        int maxCherries = INT_MIN;
        for(int d1 : v){
            for(int d2 : v){
                int y1 = j1 + d1;
                int y2 = j2 + d2;

                if(y1 >= 0 && y1 < m && y2 >= 0 && y2 < m){
                    int cherries = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                    int next = helper(grid, i + 1, y1, y2, v,dp);
                    maxCherries = max(maxCherries, cherries + next);
                }
            }
        }

        return dp[i][j1][j2]=maxCherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        vector<int> v = {-1, 0, 1};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,INT_MIN)));
        return helper(grid, 0, 0, grid[0].size() - 1, v,dp);
    }
};
