class Solution {
public:
    int helper(vector<int> &prices,int idx,bool flag,vector<vector<int>> &dp){
        if(idx>=prices.size()) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        int profit=0;
        if(flag==true){
            profit=max(-prices[idx]+helper(prices,idx+1,false,dp),helper(prices,idx+1,flag,dp));
        }
        else{
            profit=max(prices[idx]+helper(prices,idx+2,true,dp),helper(prices,idx+1,flag,dp));
        }
        return dp[idx][flag]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(prices,0,true,dp);
    }
};