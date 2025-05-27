class Solution {
public:
    int helper(vector<int> &prices,int idx,int count,bool flag, vector<vector<vector<int>>> &dp){
        if(idx==prices.size() || count==0) return 0;
        if(dp[idx][count][flag]!=-1) return dp[idx][count][flag];
        int profit=0;
        if(flag==true){
            profit=max(-prices[idx]+helper(prices,idx+1,count,false,dp),helper(prices,idx+1,count,flag,dp));
        }
        else{
            profit=max(prices[idx]+helper(prices,idx+1,count-1,true,dp),helper(prices,idx+1,count,flag,dp));
        }
        return dp[idx][count][flag]=profit;
        
    }
    int maxProfit(vector<int>& prices) {
       vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(3, vector<int>(2, -1)));

        return helper(prices,0,2,true,dp);
    }
};