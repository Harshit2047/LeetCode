class Solution {
public:
    int helper(string &s1,string &s2,int idx1,int idx2,vector<vector<int>> &dp){
        if(idx1==s1.size() || idx2==s2.size()) return 0;
        int count=0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]) count=1+helper(s1,s2,idx1+1,idx2+1,dp);
        else{
            count=max(helper(s1,s2,idx1+1,idx2,dp) , helper(s1,s2,idx1,idx2+1,dp));
        }
        return dp[idx1][idx2] =count;
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        string s2 = s;
        reverse(s.begin(),s.end());
        return helper(s,s2,0,0,dp);
    }
};