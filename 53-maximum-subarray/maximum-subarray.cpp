class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
            ans=max(dp[i],ans);
        }
        return ans;
    }
};