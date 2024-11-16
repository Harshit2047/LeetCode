class Solution {
public:
    int helper(vector<int> &nums, int target, int idx, vector<vector<int>> &dp) {
        if (idx == nums.size()) {
            return target == 0 ? 0 : INT_MIN;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int skip = helper(nums, target, idx + 1,dp);
        if(target<nums[idx]) return dp[idx][target]= skip;
        int take = 1+helper(nums, target - nums[idx], idx + 1,dp);
        
        return dp[idx][target]=max(skip, take);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        int ans= helper(nums, target, 0,dp);
        if(ans<0) return -1;
        else return ans;
    }
};
