class Solution {
public:
    map<int,map<int,int>> dp;
    int helper(int idx,int prev,vector<vector<int>> &intervals){
        if(prev>=intervals.size()-1) return 0;
        if(idx==intervals.size()) return 1e9;
        if(dp.count(idx) && dp[idx].count(prev)) return dp[idx][prev];
        if(intervals[idx][0]<=prev){
            int pick = 1+helper(idx+1,intervals[idx][1],intervals);
            int npic = helper(idx+1,prev,intervals);
            return dp[idx][prev]=min(pick,npic);
        }else{
            return dp[idx][prev]=1e9;
        }
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals;
        for(int i=0;i<ranges.size();i++) intervals.push_back({(i-ranges[i]),(i+ranges[i])});
        sort(intervals.begin(),intervals.end());
        int val = helper(0,0,intervals);
        if(val==1e9) return -1;
        else return val;
    }
};