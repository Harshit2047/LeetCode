class Solution {
public:
    bool isPer(int n){
        int ok=sqrt(n);
        return ok*ok==n;
    }
    int helper(int n ,vector<int> &dp){
        if(isPer(n)==true) return 1;
        int ok=INT_MAX;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            int count=helper(i*i,dp)+helper(n-i*i,dp);
             ok=min(ok,count);
        }

        return dp[n]=ok;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};