class Solution {
public:
    int helper(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &dp){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        if(matrix[i][j]==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int down=helper(matrix,i+1,j,dp);
        int right=helper(matrix,i,j+1,dp);
        int digonal=helper(matrix,i+1,j+1,dp);
        return dp[i][j]=1+min({down,right,digonal});
    }
    int countSquares(vector<vector<int>>& matrix) {
        int count=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                count+=helper(matrix,i,j,dp);
            }
        }
        return count;
        
    }
};