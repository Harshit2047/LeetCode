class Solution {
public:
    bool isPerfect(int n){
        int x=sqrt(n);
        return x*x==n;
    }
    int helper(int n,vector<int> &dp){
        if(isPerfect(n)) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            int ways=helper(i*i,dp)+helper(n-i*i,dp);
            ans=min(ways,ans);
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
       return helper(n,dp);
    }
};