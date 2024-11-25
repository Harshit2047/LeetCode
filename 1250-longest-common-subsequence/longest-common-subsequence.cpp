class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int p = (i>0 && j>0)? dp[i-1][j-1] : 0;
                int q = (i>0)? dp[i-1][j] : 0;
                int r = (j>0)? dp[i][j-1] : 0;

                if(text1[i]==text2[j]){
                    dp[i][j]=1+p;
                }
                else{
                    dp[i][j]=max(q,r);
                }
            }
        }
        return dp[n1-1][n2-1];
    }
};