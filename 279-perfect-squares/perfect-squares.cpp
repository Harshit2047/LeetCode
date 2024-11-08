class Solution {
public:
    bool isPerfect(int n){
        int s=sqrt(n);
        return s*s==n;
    }
    int healper(int n,vector<int> &dp){
        if(isPerfect(n)) return 1;
        if(dp[n]!=-1) return dp[n];
        int m=INT_MAX;
        for(int i=1;i*i<=n;i++){
            m=min(m,healper(i*i,dp)+healper(n-i*i,dp));
        }
        return dp[n]=m;
    }
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        return healper(n,dp);
    }
};