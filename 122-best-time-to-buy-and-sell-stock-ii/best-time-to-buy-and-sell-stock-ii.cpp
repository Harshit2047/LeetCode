class Solution {
public:

    int helper(vector<int> &prices,bool flag,int idx,vector<vector<int>> &dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][flag]!=-1) return dp[idx][flag];
        int take=INT_MIN;
        if(flag==false) take=helper(prices,true,idx+1,dp)-prices[idx];
        int sell=INT_MIN;
        int skip=helper(prices,flag,idx+1,dp);
        if(flag==true){
            sell=helper(prices,false,idx+1,dp)+prices[idx];
        }
        return dp[idx][flag] =max({take,skip,sell});
        
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
       vector<vector<int>> dp(n+1 ,vector<int>(2, -1));

       return helper(prices,false,0,dp);
        
    }
};