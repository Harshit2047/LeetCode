class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long> preSum(nums.size());
        vector<long long > postSum(nums.size());
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
            preSum[i]=sum;
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum=sum+nums[i];
            postSum[i]=sum;
        }
        int count=0;
        for(int i=0;i<=nums.size()-2;i++){
            if(preSum[i]>=postSum[i+1]) count++;
        }
        return count;
    }
};