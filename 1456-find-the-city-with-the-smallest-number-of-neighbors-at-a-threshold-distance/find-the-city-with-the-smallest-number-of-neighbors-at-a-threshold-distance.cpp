class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            dp[u][v] = wt;
            dp[v][u] = wt; 
        }

        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) { 
                for (int j = 0; j < n; j++) { 
                    if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]); 
                    }
                }
            }
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && dp[i][j] <= distanceThreshold) {
                    ans[i]++;
                }
            }
        }

       
        int minCount = INT_MAX, city = -1;
        for (int i = 0; i < n; i++) {
            if (ans[i] <= minCount) { 
                minCount = ans[i];
                city = i;
            }
        }

        return city; 
    }
};
