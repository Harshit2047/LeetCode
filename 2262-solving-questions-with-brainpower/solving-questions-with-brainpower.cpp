class Solution {
public:
    long long helper(vector<vector<int>> &questions,int idx,vector<long long> &dp){
        if(idx>=questions.size()){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        long long take=questions[idx][0]+helper(questions,idx+questions[idx][1]+1,dp);
        long long notTake=helper(questions,idx+1,dp);
        return dp[idx]= max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(),-1);
        return helper(questions,0,dp);
    }
};