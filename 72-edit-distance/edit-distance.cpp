class Solution {
public:
    int helper(string &s1,string &s2,int idx1,int idx2,vector<vector<int>> &dp){
        if(idx1==-1) return idx2+1;
        if(idx2==-1) return idx1+1;
        int count=0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]) count=helper(s1,s2,idx1-1,idx2-1,dp);
        else{
            int insert=helper(s1,s2,idx1,idx2-1,dp);
            int del=helper(s1,s2,idx1-1,idx2,dp);
            int replace=helper(s1,s2,idx1-1,idx2-1,dp);
            count= 1 + min(insert,min(del,replace));
        }
        return dp[idx1][idx2] = count;
    }
    int minDistance(string word1, string word2) {
        int s1=word1.size();
        int s2=word2.size();
        vector<vector<int>> dp(s1+1,vector<int>(s2+1,-1));
        return helper(word1,word2,s1-1,s2-1,dp);
    }
};