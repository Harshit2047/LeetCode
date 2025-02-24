class Solution {
public:
    int helper(int mid,vector<int> &nums,int k){
        int count=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                count++;
                sum=nums[i];
            }
            else sum+=nums[i];
        }
        return (count<=k);
    }
    int splitArray(vector<int>& nums, int k) {
        int i=INT_MIN;
        for(auto x:nums) i=max(i,x);
        int j=0;
        for(auto x:nums) j+=x;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(helper(mid,nums,k)){
                j=mid-1;
                ans=mid;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};