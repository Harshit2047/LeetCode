class Solution {
public:
    long long helper(vector<int> &nums,int x,int idx,bool temp,vector<vector<long long>> &dp){
        if(idx==nums.size()) return 0;
        long long take=0;
        if(dp[idx][temp]!=-1) return dp[idx][temp];
        if((temp && nums[idx]%2==0)) {
            take=nums[idx]+helper(nums,x,idx+1,nums[idx]%2==0,dp);
        }
        else if(!temp && nums[idx]%2!=0){
            take=nums[idx]+helper(nums,x,idx+1,nums[idx]%2==0,dp);
        }
        else{
            take=nums[idx]-x+helper(nums,x,idx+1,nums[idx]%2==0,dp);
        }
        
        long long notTake=helper(nums,x,idx+1,temp,dp);
        return dp[idx][temp] =  max(take,notTake);
    }
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>> dp(nums.size()+1,vector<long long>(2,-1));
        if(nums[0]%2==0) return helper(nums,x,0,true,dp);
        else return helper(nums,x,0,false,dp);

    }
};