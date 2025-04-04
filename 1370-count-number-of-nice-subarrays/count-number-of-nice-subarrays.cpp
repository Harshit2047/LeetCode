class Solution {
public:
    int helper(vector<int> &nums,int k){
        int i=0;
        int j=0;
        int count=0;
        int Oddcount=0;
        while(j<nums.size()){
            if(nums[j]%2!=0) Oddcount++;
            while(Oddcount>k){
                if(nums[i]%2!=0) Oddcount--;
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};