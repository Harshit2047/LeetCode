class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            int target=0-nums[i];
            int low=i+1;
            int high=nums.size()-1;
            while(low<high){
                if(nums[low]+nums[high]==target){
                    st.insert({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]<target){
                    low++;
                }
                else{
                    high--;
                }
            }
        }
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};