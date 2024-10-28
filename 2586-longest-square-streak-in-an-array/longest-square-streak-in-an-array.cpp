class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<long long> h;
        for(int i=0;i<nums.size();i++){
            h.insert(nums[i]);
        }
        vector<vector<long long>>ans;
      //  sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            vector<long long> v;
            v.push_back(nums[i]);
            while(1){
                long long squared = static_cast<long long>(nums[i]) * nums[i];
                if(h.find(squared)!=h.end()){
                    v.push_back(nums[i]*nums[i]);
                    nums[i]=nums[i]*nums[i];
                }
                else break;
            }
            ans.push_back(v);
        }
        long long ok=INT_MIN;
        for(auto i: ans){
            ok=max(ok,static_cast<long long>(i.size()));
            
        }
        if(ok==1) return -1;
        return ok;
    }
};