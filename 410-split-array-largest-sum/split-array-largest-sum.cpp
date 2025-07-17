class Solution {
public:
    bool helper(vector<int> &nums,int k,int sum){
        int count=1;
        int temp=sum;
        for(int i=0;i<nums.size();i++){
            if(temp-nums[i]<0){
                count++;
                temp=sum;
            }
            temp-=nums[i];
        }
        if(count<=k) return true;
        else return false;
    }
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return false;
        int low=INT_MIN;
        int high=0;
        for(auto i:nums){
            low=max(low,i);
            high+=i;
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(helper(nums,k,mid)){
                 high=mid-1;
                ans=mid;
            }
            else{
               low=mid+1;
            }
        }
        return ans;

    }
};