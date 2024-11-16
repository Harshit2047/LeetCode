class Solution {
public:
    long healper(vector<int> &coins,int amount,int idx,vector<vector<int>> &dp){
        if(idx==coins.size()){
            if(amount==0) return 0;
            else return INT_MAX;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        long leave=healper(coins,amount,idx+1,dp);
        if(amount<coins[idx]) return dp[idx][amount]=leave;
        long pick=1+healper(coins,amount-coins[idx],idx,dp);
        return dp[idx][amount]=min(leave,pick);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        int ans=(int)healper(coins,amount,0,dp);
        if(INT_MAX==ans) return -1;
        else return ans;
    }
};