class Solution {
public:
    int helper(vector<int>& nums, int idx, int prevIdx, vector<vector<int>>& dp) {
        if (idx == nums.size()) return 0;
        
        if (dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];
        
        int take = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
            take = 1 + helper(nums, idx + 1, idx, dp); // Take current element
        }
        int notTake = helper(nums, idx + 1, prevIdx, dp); // Skip current element
        
        return dp[idx][prevIdx + 1] = max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // Use n+1 to handle -1-based indexing for prevIdx
        return helper(nums, 0, -1, dp);
    }
};
