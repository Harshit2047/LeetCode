class Solution {
public:
    int helper(vector<int> &nums,int k){
        int i=0;
        int j=0;
        int ans=0;
        unordered_map<int,int> mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            while(mp.size()>k){
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
        
                 ans+=j-i+1;
            
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k) - helper(nums,k-1);
    }
};