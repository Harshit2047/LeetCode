class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       int minidx=-1;
       int  maxidx=-1;
       int culidx=-1;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK || nums[i]>maxK){
                culidx=i;
            }
            if(minK==nums[i]) minidx=i;
             if(maxK==nums[i]) maxidx=i;
            long long smaller=min(minidx,maxidx);
            long long temp=smaller-culidx;
            ans+=(temp<=0)? 0:temp;
        }
        return ans;
    }
};