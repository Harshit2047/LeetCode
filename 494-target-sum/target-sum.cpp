class Solution {
public:
    long long healper(vector<int> &nums,int target,int idx,int val,vector<vector<int>> &dp,int sum){
        if(idx==nums.size()){
            if(target==val) return 1;
            else return 0; 
        }
        if(dp[idx][val+sum]!=-1) return dp[idx][val+sum];
        return dp[idx][val+sum]=healper(nums,target,idx+1,val+nums[idx],dp,sum)+healper(nums,target,idx+1,val-nums[idx],dp,sum);
        
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto i:nums) sum=sum+i;
        vector<vector<int>> dp(nums.size()+1,vector<int>((sum*2)+1,-1));
        return healper(nums,target,0,0,dp,sum);
    }
};