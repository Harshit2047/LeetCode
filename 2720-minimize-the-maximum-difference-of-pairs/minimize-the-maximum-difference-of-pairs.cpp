class Solution {
public:
    int helper(vector<int> &nums,int val){
        int count=0;
        int n=nums.size();
        int i=0;
        while(i<n-1){
            if(nums[i+1]-nums[i]<=val){
                i+=2;
                count++;
            } 
            else i++;
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[n-1]-nums[0];
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(helper(nums,mid)<p) low=mid+1;
            else{
                high=mid-1;
                ans=min(ans,mid);
            }
        }
        return ans;
    }
};