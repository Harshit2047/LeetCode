


class Solution {
public:
int maxi(string &s,string &s2,int i,int j,vector<vector<int>>&dp)
{
    if(i==s.size())
    {
        return 0;
    }
    if(j==s2.size())
    {
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int sum=0;
    if(s[i]==s2[j])
    {
       sum= 1+ maxi(s,s2,i+1,j+1,dp);
    }
    else{
        sum=max(maxi(s,s2,i+1,j,dp),maxi(s,s2,i,j+1,dp));

    }
    return dp[i][j]=sum;
}
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(),vector<int>(text2.size(),-1));
        return maxi(text1,text2,0,0,dp);
    }

};