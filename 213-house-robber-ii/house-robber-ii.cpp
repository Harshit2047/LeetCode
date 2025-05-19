class Solution {
public:
    int helper(vector<int> &nums,int start,int size){
        if(start==size) return max(nums[0],nums[1]);
        vector<int> dp(nums.size());
        dp[start]=nums[start];
        dp[start+1]=max(dp[start],nums[start+1]);
        for(int i=start+2;i<=size;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[size];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        return max(helper(nums,0,nums.size()-2),helper(nums,1,nums.size()-1));
    }
};