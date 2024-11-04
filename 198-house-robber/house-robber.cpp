class Solution {
public:
    int healper(vector<int> nums,int idx,vector<int> &v){
        if(idx>=nums.size()) return 0;
        if(v[idx]!=-1) return v[idx];
        return v[idx] = max(nums[idx]+healper(nums,idx+2,v),healper(nums,idx+1,v)); 
    }
    int rob(vector<int>& nums) {
        vector<int> v(nums.size()+1,-1);
        return healper(nums,0,v);
        
    }
};