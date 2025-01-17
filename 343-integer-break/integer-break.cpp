class Solution {
public:
    int helper(int n,vector<int> &dp){
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            int pro=i*max(n-i,helper(n-i,dp));
            ans=max(ans,pro);
        }
        return dp[n]= ans;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};