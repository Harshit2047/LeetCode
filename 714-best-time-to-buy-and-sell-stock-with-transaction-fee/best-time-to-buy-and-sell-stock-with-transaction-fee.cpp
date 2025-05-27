class Solution {
public:
    int helper(vector<int> &prices,int idx,bool flag,int fee,vector<vector<int>> &dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        int profit=0;
        if(flag){
            profit=max(-prices[idx]+helper(prices,idx+1,false,fee,dp),helper(prices,idx+1,flag,fee,dp));
        }
        else{
            profit=max(prices[idx]+helper(prices,idx+1,true,fee,dp)-fee,helper(prices,idx+1,flag,fee,dp));
        }
        return dp[idx][flag]=profit;

    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(prices,0,true,fee,dp);
    }
};