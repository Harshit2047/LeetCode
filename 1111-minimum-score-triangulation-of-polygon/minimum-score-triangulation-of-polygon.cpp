class Solution {
public:
    int helper(vector<int> &values,int start,int end , vector<vector<int>> &dp){
        if(start+1==end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans=INT_MAX;
        for(int k=start+1;k<end;k++){
            ans=min(ans,values[start]*values[end]*values[k] + helper(values,start,k,dp)+helper(values,k,end,dp));
        }
        return dp[start][end]= ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(values,0,values.size()-1,dp);
    }
};