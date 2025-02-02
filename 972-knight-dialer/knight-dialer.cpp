class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> adj{
        {4,6},
        {6,8},
        {9,7},
        {8,4},
        {3,9,0},
        {},
        {1,7,0},
        {2,6},
        {3,1},
        {2,4}
        };
    int solve(int n,int whereIamAt,vector<vector<int>> &dp){
        if(n==0) return 1;
        if(dp[n][whereIamAt]!=-1) return dp[n][whereIamAt];
        int count=0;
        for(int i=0;i<adj[whereIamAt].size();i++){
            count = (count + solve(n-1, adj[whereIamAt][i], dp)) % MOD;
;
        }
        return dp[n][whereIamAt]=count;
    }
    int knightDialer(int n) {
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(10,-1));
        for(int i=0;i<=9;i++){
            ans=(ans+solve(n-1,i,dp))%MOD;
        }
        return ans%MOD;
        
    }
};