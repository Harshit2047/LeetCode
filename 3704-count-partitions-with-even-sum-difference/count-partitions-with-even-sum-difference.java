class Solution {
    public int countPartitions(int[] nums) {
        int n=nums.length;
        int[] pre=new int[n];
        int[] suf=new int[n];
        for(int i=0;i<nums.length;i++){
            if(i==0) pre[i]=nums[i];
            else pre[i]=pre[i-1]+nums[i];
        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1) suf[i]=nums[i];
            else suf[i]=suf[i+1]+nums[i];
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            if((pre[i]-suf[i+1])%2==0) count++;
        }
        return count;
    }
}