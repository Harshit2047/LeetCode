class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        unordered_map<long long, int> mp;
        for(int i=0;i<nums.size();i++){
            mp[i-nums[i]]++;
        }
        long long ans=0;
        for(auto it:mp){
            while(it.second--){
                n=n-1;
                ans=ans+n-it.second;
            }
            if(it.second==0) mp.erase(it.first);
        }
        return ans; 
    }
};