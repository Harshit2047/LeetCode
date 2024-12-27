

class Solution {
public:
    bool helper(vector<int> &nums,int idx,int sum,int s,int Fsum,vector<vector<int>> &dp){
        if(idx==s) return false;
        if(Fsum>sum) return false;
        if(Fsum==sum) return true;
        if(dp[idx][Fsum]!=-1) return dp[idx][Fsum];
        bool take=helper(nums,idx+1,sum,s,Fsum+nums[idx],dp);
        bool leave=helper(nums,idx+1,sum,s,Fsum,dp);
        return dp[idx][Fsum]=(take|| leave);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int s=nums.size();
        
       for(int i=0;i<nums.size();i++){
            sum=sum+nums[i];
       } 
       if(sum%2!=0) return false; 
       int Fsum=0;
       vector<vector<int>> dp(s + 1, vector<int>((sum / 2) + 1, -1));
       return helper(nums,0,sum/2,s,Fsum,dp);
    }
};