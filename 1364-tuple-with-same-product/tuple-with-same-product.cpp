class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                    mp[nums[i]*nums[j]]++;
            }
        }
        int count=0;
        for(auto it=mp.begin();it!=mp.end();it++){
           int freq=it->second;
           count+=(freq*(freq-1))/2;
        }
        return count *8 ;
        
    }
};