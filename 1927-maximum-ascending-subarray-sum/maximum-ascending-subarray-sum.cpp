class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans=INT_MIN;
        int temp=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                temp+=nums[i];
            }
            else {
                ans=max(ans,temp);
                temp=nums[i];
            }
            ans=max(ans,temp);
        }
        return ans==INT_MIN ? nums[0]:ans;
    }
};