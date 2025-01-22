class Solution {
public:
    int helper(vector<int> &coins, int amount, int idx, vector<vector<int>> &dp) {
        if (amount == 0) return 1; 
        if (idx == coins.size()) return 0; 
        if (dp[idx][amount] != -1) return dp[idx][amount]; 

        int include = 0;
        if (amount >= coins[idx]) {
            include = helper(coins, amount - coins[idx], idx, dp);
        }
        int exclude = helper(coins, amount, idx + 1, dp); 

        return dp[idx][amount] = include + exclude;
    }

    int change(int amount, vector<int> &coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return helper(coins, amount, 0, dp);
    }
};
