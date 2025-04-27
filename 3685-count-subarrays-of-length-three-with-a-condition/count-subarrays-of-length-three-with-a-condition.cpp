class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int i=0;
        int j=2;
        int ans=0;
        while(j<nums.size()){
            float temp=(float)nums[j-1]/2;
            cout<<temp;
            if((nums[i])+(nums[j])==(temp)) ans++;
            i++;
            j++;
        }
        return ans;
    }
};