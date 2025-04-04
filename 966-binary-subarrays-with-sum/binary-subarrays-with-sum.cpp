class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int temp=sum;
            sum=sum+nums[i];
            // if(temp==sum) count=count+1;
            if(sum==k) count++;
            // if(nums[i]==k) count++;
            
            if(mp.find(sum-k)!=mp.end()){
                    count=count+mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};