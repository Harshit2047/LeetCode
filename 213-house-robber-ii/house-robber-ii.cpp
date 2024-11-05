class Solution {
public:
    int healper(vector<int> &nums,int idx,int size,vector<int> &dp){
        if(idx>=size) return 0;
        if(idx==size-1) return nums[idx];
        if(dp[idx]!=-1) return dp[idx];
        int take=nums[idx]+healper(nums,idx+2,size,dp);
        int leave=healper(nums,idx+1,size,dp);
        return dp[idx] = max(leave,take);
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        int includingFirst=healper(nums,0,n-1,dp);
        vector<int> ap(n,-1);
        int excludingFirst=healper(nums,1,n,ap);
        return max(includingFirst,excludingFirst);
    }
};