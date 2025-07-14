class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                ans=max(ans,nums[i]);
                 pre=1;
            }
            else{
                pre*=nums[i];
                ans=max(ans,pre);
            }
        }
        int suf=1;
        for(int i=nums.size()-1;i>=0 ;i--){
            if(nums[i]==0){
                ans=max(ans,nums[i]);
                 suf=1;
            }
            else{
                suf*=nums[i];
                ans=max(ans,suf);
            }
        }
        return ans;
    }
};