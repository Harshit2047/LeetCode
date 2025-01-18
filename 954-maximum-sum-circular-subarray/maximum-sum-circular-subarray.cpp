class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int Maxans=INT_MIN;
        int maxSum=0;
        int minSum=0;
        int MinAns=INT_MAX;
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            maxSum=max(nums[i]+maxSum,nums[i]);
            Maxans=max(Maxans,maxSum);

            minSum=min(nums[i]+minSum,nums[i]);
            MinAns=min(minSum,MinAns);

            totalSum=totalSum+nums[i];
        }

        if(totalSum==MinAns) return Maxans;
        return max(Maxans,totalSum-MinAns);


        
        
    }
};