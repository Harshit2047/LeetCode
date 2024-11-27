class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int n=nums.size();
        if(n==1){
            ans.push_back(nums[0]);
            return ans;
        }
        if(nums[0]!=nums[1] && nums[0]+1!=nums[1]) ans.push_back(nums[0]);
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]+1 == nums[i+1] || nums[i]-1 == nums[i-1] || nums[i]==nums[i+1] || nums[i]==nums[i-1]){
                continue;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        if(nums[n-2]!=nums[n-1] && nums[n-2]+1!=nums[n-1]) ans.push_back(nums[n-1]);
        return ans;
    }

};