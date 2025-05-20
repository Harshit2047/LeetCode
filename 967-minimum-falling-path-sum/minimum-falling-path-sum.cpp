class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int leftup=(j-1>=0) ? dp[i-1][j-1]:INT_MAX;
                int up=dp[i-1][j];
                int rightup=(j+1<m) ? dp[i-1][j+1]:INT_MAX;
                dp[i][j]=matrix[i][j]+min({leftup,up,rightup});
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,dp[n-1][i]);
        }
     

        return ans;
    }
};