class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ansI=1;
        int ansD=1;
        int ans=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]) ansI++;
            else ansI=1;

            if(nums[i]>nums[i+1]) ansD++;
            else ansD=1;
            ans=max({ans,ansD,ansI});
            }

    return ans==INT_MIN ? 1: ans;



        
    }
};