class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> including(n);
        including[0]=nums[0];
     if(n>1) including[1]=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            including[i]=max(nums[i]+including[i-2],including[i-1]);
        }
        vector<int> excluding(n);
       
     if(n>1)    excluding[1]=nums[1];
     if(n>2)   excluding[2]=max(nums[1],nums[2]);
        for(int i=3;i<n;i++){
            excluding[i]=max(nums[i]+excluding[i-2],excluding[i-1]);
        }

        return max(excluding[n-1],including[n-2]);
    }
};