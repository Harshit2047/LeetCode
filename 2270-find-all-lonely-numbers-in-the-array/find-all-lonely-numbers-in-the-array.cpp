class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto i:nums){
           mp[i]++;
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end() && mp[nums[i]]>1 || mp.find(nums[i]+1)!=mp.end()  || mp.find(nums[i]-1)!=mp.end()  ){
                continue;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }

};