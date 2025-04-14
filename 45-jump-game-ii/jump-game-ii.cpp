#include <climits>
class Solution {
public:
    int helper(vector<int> &nums, int idx, vector<int> &dp) {
        if (idx >= nums.size() - 1) return 0;
        if (dp[idx] != -1) return dp[idx];
        int ans = INT_MAX;
        for (int i = 1; i <= nums[idx]; i++) {
            int count = helper(nums, idx + i, dp);
            if (count != INT_MAX) {
                ans = min(ans, 1 + count);
            }
        }
        return dp[idx] = ans;
    }

    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int range = nums[0];
        int ans = INT_MAX;
        vector<int> dp(nums.size(), -1);
        for (int i = 1; i <= range; i++) {
            int count = helper(nums, i, dp);
            if (count != INT_MAX) {
                ans = min(ans, 1 + count);
            }
        }
        return ans;
    }
};
