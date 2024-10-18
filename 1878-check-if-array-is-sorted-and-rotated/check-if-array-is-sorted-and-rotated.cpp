class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n=nums.size();
       for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]) count++;
       }
       if(count==0) return true;
       if(count==1 && nums[0]>=nums[n-1]) return true;
       else return false;
    }
};