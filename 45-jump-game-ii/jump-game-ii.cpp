class Solution {
public:
    int helper(vector<int> &nums,int idx,vector<int> &dp){
        if(idx>=nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int count=0;
        int ans=10000;
        for(int i=1;i<=nums[idx];i++){
            int count=1+helper(nums,idx+i,dp);
            ans=min(ans,count);
        }
        return dp[idx]=ans;
    }
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int range=nums[0];
        int ans=10000;
        vector<int> dp(nums.size(),-1);
        for(int i=1;i<=range;i++){
            int count=1+helper(nums,i,dp);
            ans=min(ans,count);
        }
        return ans;
    }
};