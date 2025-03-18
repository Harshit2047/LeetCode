class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int neededPair=nums.size()/2;
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int pairs=0;
        for(auto i:mp){
            pairs+=i.second/2;
        }
        return pairs==neededPair;
    }
};