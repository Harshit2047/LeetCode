class Solution {
public:
    int healper(vector<int> &cost,int idx,int size,vector<int> &dp){
        if(idx>=size) return 0;
        if(idx==size-1) return cost[idx];
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = (cost[idx]+min(healper(cost,idx+1,size,dp),healper(cost,idx+2,size,dp)));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return min(healper(cost,0,n,dp),healper(cost,1,n,dp)) ;
    }
};