class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int i=0;
        int j=nums.size()-1;
        bool ans=false;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(nums[mid]==target){
                ans=true;
                break;
            }
            if(nums[mid] == nums[i] && nums[mid] == nums[j])
{
       i++;
       j--;
}
            else if(nums[i]<=nums[mid]){
                if(nums[i]<=target && nums[mid]>target){
                    j=mid-1;
                }
                else i=mid+1;
            }
            else{
                if(nums[mid]<target && nums[j]>=target){
                    i=mid+1;
                }
                else j=mid-1;
            }
        }
        return ans;
    }
};