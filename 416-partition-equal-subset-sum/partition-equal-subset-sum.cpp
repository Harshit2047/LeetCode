class Solution {
public:
   
    bool canPartition(vector<int>& nums) {
        int target=0;
        for(int i=0;i<nums.size();i++){
            target+=nums[i];
        }
        if(target%2!=0) return false;
        target=target/2;
        vector<vector<bool>> dp(nums.size(),vector<bool>(target+1));
        for(int i=0;i<dp.size();i++){
            dp[i][0]=true;
        }
        if(nums[0]<=target)dp[0][nums[0]]=true;
        for(int i=1;i<dp.size();i++){
            for(int sum=1;sum<=target;sum++){
                bool Take=false;
                if(sum-nums[i]>=0) Take=dp[i-1][sum-nums[i]];
                bool notTake = dp[i-1][sum];
                dp[i][sum]=(notTake||Take);
            }
        }
        return dp[dp.size()-1][target];
    }
};