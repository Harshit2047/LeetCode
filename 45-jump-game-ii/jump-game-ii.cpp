class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int low=0;
        int high=0;
        int count=0;
        while(high<nums.size()-1){
            int RangeMax=INT_MIN;
            for(int i=low;i<=high;i++){
                RangeMax=max(RangeMax,i+nums[i]);
            }
            low=high+1;
            high=RangeMax;
            count++;
        }
        return count;
    }
};