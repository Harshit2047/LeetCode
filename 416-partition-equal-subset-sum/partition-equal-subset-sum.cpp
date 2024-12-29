

class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int s = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
        }

        if (sum % 2 != 0)
            return false;
        int halfSum = sum / 2;
        vector<vector<int>> dp(s+1,vector<int>(halfSum+1));
        for (int i = 0; i < s; i++) {
            for (int j = 0; j <= halfSum; j++) {
                bool take = (i>0) ? (j-nums[i]>=0) ? dp[i-1][j-nums[i]]==1 : j==0 : 0;
                bool leave = (i>0) ? dp[i-1][j]==1 : j==0;
                dp[i][j] = (take || leave);
            }
        }
        return dp[s-1][halfSum]==1;
    }
};