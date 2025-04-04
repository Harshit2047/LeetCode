class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countZ=0;
        int i=0;
        int j=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]==0) countZ++;
            while(countZ>k){
                if(nums[i]==0) countZ--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};