class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target=0-nums[i];
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                if(nums[low]+nums[high]==target){
                    ans.push_back({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                    while(low<nums.size() && nums[low]==nums[low-1])low++;
                    while(high<nums.size()-1 && nums[high]==nums[high+1])high--;
                }
                else if(nums[low]+nums[high]<target){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        return ans;
    }
};