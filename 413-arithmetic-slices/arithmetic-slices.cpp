class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        vector<int> dp(nums.size());
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<nums.size();i++){
            if(nums[i-1]-nums[i-2]==nums[i]-nums[i-1]){
                dp[i]=1+dp[i-1];
            }
            else{
                dp[i]=0;
            }
        }
        int ans=0;
        for(int i=0;i<dp.size();i++){
            ans=ans+dp[i];
        }
        return ans;
    }
};