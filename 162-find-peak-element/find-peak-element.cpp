class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=1;
        int j=nums.size()-2;
        int ans=-1;
        int n=nums.size()-1;
        if(n==0) return 0;
        if(nums[0]>nums[1]){
            ans=0;
        }
        if(nums[n]>nums[n-1]){
            ans=n;
        }
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                ans=mid;
                break;
            }
            if(nums[mid]<nums[mid+1]){
                i=mid+1;
            }
            else if(nums[mid]>nums[mid+1]){
                j=mid-1;
            }
        }
        return ans;
    }
};