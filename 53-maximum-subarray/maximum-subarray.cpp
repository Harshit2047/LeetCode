class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max1=INT_MIN;
        if(nums.size()==1) return nums[0];
        for(int ele:nums){
            sum+=ele;
            max1=max(max1,sum);
            if(sum<0) sum=0;
            
        }
        return max1;
    }
};