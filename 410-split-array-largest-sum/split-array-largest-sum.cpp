class Solution {
public:
    bool helper(int mid,vector<int> &nums,int k){
        int count=1;
        int take=mid;
        for(int i=0;i<nums.size();i++){
            if(take<nums[i]){
                count++;
                take=mid;
                take-=nums[i];
            }
            else take-=nums[i];
        }
        return count<=k;
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