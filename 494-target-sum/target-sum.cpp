class Solution {
public:
    int helper(vector<int> &nums,int target,int idx,int size,int sum,int total,vector<vector<int>> &dp){
        if(idx==size){
            if(target==sum) return 1;
            else return 0;
        }
        if(dp[idx][sum+total]!=-1) return dp[idx][sum+total];
        int postive=helper(nums,target,idx+1,size,sum+nums[idx],total,dp);
        int negative=helper(nums,target,idx+1,size,sum-nums[idx],total,dp);
        return dp[idx][sum+total]=(negative+postive);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int total=0;
        for(auto i:nums){
            total=total+i;
        }
        vector<vector<int>> dp(nums.size()+1,vector<int>((total*2)+1,-1));
        return helper(nums,target,0,nums.size(),0,total,dp);
    }
};