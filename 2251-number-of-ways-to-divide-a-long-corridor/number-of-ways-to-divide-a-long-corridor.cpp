class Solution {
public:
const int M=1e9+7;
    int helper(string &s,int idx,int count,vector<vector<int>> &dp){
        if(idx==s.length() && count==2) return 1;
        if(idx==s.length()) return 0;
        if(dp[idx][count]!=-1) return dp[idx][count];
        int take=0;
        if(count==2) {
            if(s[idx]=='S') return dp[idx][count]= helper(s,idx+1,1,dp);
            else return dp[idx][count]= (helper(s,idx+1,0,dp)+helper(s,idx+1,count,dp))%M;
        }
        else if(s[idx]=='S'){
           take= helper(s,idx+1,count+1,dp);
        }
        else {
            take=helper(s,idx+1,count,dp);
        }
        return dp[idx][count]=take;
    }
    int numberOfWays(string corridor) {
        int n=corridor.size();
        vector<vector<int>> dp(n,vector<int>(3,-1));
        return helper(corridor,0,0,dp);
    }
};