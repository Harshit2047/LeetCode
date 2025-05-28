class Solution {
public:
    int helper(vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& dp) {
        if (idx == nums.size()) return 0;
        
        if (dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];
        
        int take = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            take = 1 + helper(nums, idx + 1, idx, dp); 
        }
        int notTake = helper(nums, idx + 1, prevIdx, dp);
        
        return dp[idx][prevIdx + 1] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
        vector<int> dp(nums.size(),1);
        for(int i=0;i<n;i++){
            int maxValue=0;
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    maxValue=max(maxValue,dp[j]);
                }
            }
            dp[i]=dp[i]+maxValue;
            ans=max(ans,dp[i]);
        }
        
        return ans;
    }
};
