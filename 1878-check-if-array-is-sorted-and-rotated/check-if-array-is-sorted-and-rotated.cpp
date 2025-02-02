class Solution {
public:
    bool check(vector<int>& nums) {
        int flag=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%n]){
                flag++;
            } 
        }
        if (flag>1) return false;
        return true;
        
    }
};