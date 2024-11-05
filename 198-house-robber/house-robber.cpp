class Solution {
public:
    int healper(vector<int> & nums,int idx,vector<int> &dp){
        if(idx>nums.size()-1) return 0;
        if(idx==nums.size()-1) return nums[idx];
        if(dp[idx]!=-1) return dp[idx];
        return  dp[idx] = max(nums[idx]+healper(nums,idx+2,dp),healper(nums,idx+1,dp));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
       return  healper(nums,0,dp);
    }
};