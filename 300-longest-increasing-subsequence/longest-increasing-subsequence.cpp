class Solution {
public:
    int lowerBound(vector<int> nums,int val){
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;
             if(nums[mid]<val){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(ans.size()==0 || ans.back()<nums[i]){
                ans.push_back(nums[i]);
            }
            else{
                int idx=lowerBound(ans,nums[i]);
                ans[idx]=nums[i];
            }
        }
        return ans.size();
    }
};