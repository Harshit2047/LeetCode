class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m=INT_MIN;
        vector<int>dp(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[j],dp[i]);
                }
            }
             dp[i]+=1;
           m=max(dp[i],m);
        }
        return m;
    }
};