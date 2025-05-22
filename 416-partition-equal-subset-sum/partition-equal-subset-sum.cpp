class Solution {
public:
    bool helper(vector<int> &nums,int idx,int sum,vector<vector<int>> &dp){
        if(sum==0) return true;
        if(nums.size()==idx) return false;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool Take=false;
        if(sum-nums[idx]>=0) Take=helper(nums,idx+1,sum-nums[idx],dp);
        bool notTake=helper(nums,idx+1,sum,dp);
        return dp[idx][sum]=(Take||notTake);
    }
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2!=0) return false;
        target=target/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        return helper(nums,0,target,dp);
    }
};