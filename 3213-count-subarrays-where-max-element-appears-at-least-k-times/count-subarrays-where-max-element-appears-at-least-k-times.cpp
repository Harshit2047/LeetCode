class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int M=INT_MIN;
        for(auto i:nums){
            M=max(M,i);
        }
        int i=0;
        int j=0;
        long long ans=0;
        int n=nums.size();
        while(j<nums.size()){
            if(nums[j]==M) k--;
            while(k==0){
                ans+=n-j;
                if(nums[i]==M){
                    k++;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};