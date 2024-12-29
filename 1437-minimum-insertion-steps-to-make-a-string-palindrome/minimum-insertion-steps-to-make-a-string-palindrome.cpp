class Solution {
public:
    int helper(string &s,int idx1,int idx2,vector<vector<int>> &dp){
        if(idx1>=idx2) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        int count=0;
        if(s[idx1]==s[idx2]) count=helper(s,idx1+1,idx2-1,dp);
        else{
            count=1+min(helper(s,idx1+1,idx2,dp),helper(s,idx1,idx2-1,dp));
        }
        return  dp[idx1][idx2]=count;
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        int idx2=s.size()-1;
        return helper(s,0,idx2,dp);

    }
};