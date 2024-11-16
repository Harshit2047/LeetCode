class Solution {
public:
    bool healper(int target,int idx,vector<int> &nums,vector<vector<int>> &dp){
       if (target == 0) return true; 
        if (idx == nums.size() || target < 0) return false;
        if(dp[idx][target]!=-1) return dp[idx][target]; 
        bool leave=healper(target,idx+1,nums,dp);
        bool pick=healper(target-nums[idx],idx+1,nums,dp);
        return dp[idx][target]=leave || pick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
        return healper(target,0,nums,dp);

    }
};