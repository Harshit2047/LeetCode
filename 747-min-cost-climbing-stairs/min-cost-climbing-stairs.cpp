class Solution {
public:
    int helper(vector<int>& cost,int idx, vector<int>& dp){
        if(idx<0) return 0;
        if(idx==1) return cost[idx];
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx] = cost[idx]+min(helper(cost,idx-1,dp),helper(cost,idx-2,dp));

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
       return min(helper(cost,n-1,dp),helper(cost,n-2,dp));
    }
};