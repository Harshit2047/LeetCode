class Solution {
public:
    int helper(vector<int>&nums,int target,int idx){
        if(idx==nums.size()){
            if(target==0) return 1;
            else return 0;
        }
        int neg=helper(nums,target-nums[idx],idx+1);
        int plus=helper(nums,target+nums[idx],idx+1);
        return neg+plus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums,target,0);
    }
};