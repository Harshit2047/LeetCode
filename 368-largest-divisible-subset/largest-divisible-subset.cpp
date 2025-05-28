class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        vector<int> parent(nums.size(),-1);
        int lastIdx=0;
        int maxLen=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 ){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        parent[i]=j;
                    }
                }
            }
            if(dp[i]>maxLen){
                maxLen=dp[i];
                lastIdx=i;
            }
        }
        vector<int> ans;
        while(lastIdx!=-1){
            ans.push_back(nums[lastIdx]);
            lastIdx=parent[lastIdx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};