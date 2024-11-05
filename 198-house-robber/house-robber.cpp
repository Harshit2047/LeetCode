class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n);
       v[0]=nums[0];
     if(n>1)  v[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            v[i]=max(nums[i]+v[i-2],v[i-1]);
        }
        return v[n-1];
    }
};