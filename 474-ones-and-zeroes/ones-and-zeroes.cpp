class Solution {
public:
    int helper(vector<pair<int, int>> &counts, int idx, int m, int n, vector<vector<vector<int>>> &dp) {
        if (idx == counts.size()) return 0; // Base case: no more strings to consider
        if (dp[idx][m][n] != -1) return dp[idx][m][n]; // Return cached result

        int notTake = helper(counts, idx + 1, m, n, dp); // Skip current string

        int take = 0;
        int count0 = counts[idx].first;
        int count1 = counts[idx].second;

        if (m >= count0 && n >= count1) { // Take current string if possible
            take = 1 + helper(counts, idx + 1, m - count0, n - count1, dp);
        }

        return dp[idx][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> counts; // Store counts of 0s and 1s for each string

        for (string &s : strs) {
            int count0 = 0, count1 = 0;
            for (char c : s) {
                if (c == '0') count0++;
                else count1++;
            }
            counts.push_back({count0, count1});
        }

        // Memoization table: dp[idx][m][n]
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return helper(counts, 0, m, n, dp);
    }
};
