class Solution {
public:
    int helper(vector<int> &days,vector<int> &cost,int idx,int Reach,vector<vector<int>> &dp){
        if(idx==days.size()) return 0;
        if(dp[idx][Reach]!=-1) return dp[idx][Reach];
        if(Reach>=days[idx]) return dp[idx][Reach] =  helper(days,cost,idx+1,Reach,dp);
        int one=cost[0]+helper(days,cost,idx+1,days[idx],dp);
        int seven=cost[1]+helper(days,cost,idx+1,days[idx]+6,dp);
        int thirty=cost[2]+helper(days,cost,idx+1,days[idx]+29,dp);

        return dp[idx][Reach] = min(one,min(seven,thirty));
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<vector<int>> dp(days.size(),vector<int>(400,-1));
        return helper(days,costs,0,0,dp);
    }
};