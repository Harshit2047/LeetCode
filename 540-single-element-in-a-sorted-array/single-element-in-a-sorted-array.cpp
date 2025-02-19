class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ok=0;
        for(int i=0;i<nums.size();i++){
            ok=ok^nums[i];
        }
        return ok;
    }
};