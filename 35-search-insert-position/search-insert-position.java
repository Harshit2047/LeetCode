class Solution {
    public int searchInsert(int[] nums, int target) {
        int i=0,j=nums.length-1,ans=0;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]<target) i=mid+1;
            else j=mid-1;
            ans=mid;
        }
        if(nums[ans]<target) return ans+1;
        return ans;
    }
}