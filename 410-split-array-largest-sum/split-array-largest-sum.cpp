class Solution {
public:
    int helper(int mid,vector<int> &nums,int k){
        int count = 1, sum = 0;
        
        for (int num : nums) {
            if (sum + num > mid) {
                count++;  // Start a new subarray
                sum = num;
                if (count > k) return false;  // If more than k subarrays, return false
            } else {
                sum += num;
            }
        }
        
        return count <= k; 
    }
    int splitArray(vector<int>& nums, int k) {
         int i = *max_element(nums.begin(), nums.end());
        int j=0;
        for(auto x:nums) j+=x;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(helper(mid,nums,k)){
                j=mid-1;
                ans=mid;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};