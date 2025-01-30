class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        vector<int> ans;
        map<int,int> mp;
        for(auto i:nums) mp[i]++;
        for(auto i: mp){
            if(i.second>n) ans.push_back(i.first);
        }
        return ans;
    }
};