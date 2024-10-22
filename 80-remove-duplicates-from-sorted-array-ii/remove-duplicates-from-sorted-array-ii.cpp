class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int count=2;
       if(nums.size()<2) return 1;
       for(int i=2;i<nums.size();i++){
        if(nums[count-2]!=nums[i]){
            nums[count]=nums[i];
            count++;
       }
    }
     return count;
    }
};