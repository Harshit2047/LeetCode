class Solution {
public:
    int helper(string text1,string text2,int idx1,int idx2, vector<vector<int>> &dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int a=0;int b=0;int c=0;
        if(text1[idx1]==text2[idx2])  a=1+helper(text1,text2,idx1-1,idx2-1,dp);
        if(text1[idx1]!=text2[idx2]){
             b=helper(text1,text2,idx1-1,idx2,dp);
             c=helper(text1,text2,idx1,idx2-1,dp);
        }
        return dp[idx1][idx2]=max({a,b,c});
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1,vector<int>(n2));
        if(text1[0]==text2[0]) dp[0][0]=1;
        else dp[0][0]=0;
        for(int i=1;i<n1;i++){
            if(text1[i]==text2[0])dp[i][0]=1;
            else dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<n2;i++){
            if(text2[i]==text1[0]) dp[0][i]=1;
            else dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<n1;i++){
            for(int j=1;j<n2;j++){
                int a=0;
                int b=0;
                int c=0;
                if(text1[i]==text2[j])  a=1+dp[i-1][j-1];
                else{
                    b=dp[i-1][j];
                    c=dp[i][j-1];
                }
                dp[i][j]=max({a,b,c});
            }
        }
        return dp[n1-1][n2-1];
    }
};