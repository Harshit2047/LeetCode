class Solution {
    boolean helper(int mid,int threshold,int[] nums){
        int sum=0;
        for(int ele:nums){
            sum+=Math.ceil(1.0*ele/mid);
        }
        return sum<=threshold;
    }
    public int smallestDivisor(int[] nums, int threshold) {
        int max=0;
        for(int ele:nums) max=Math.max(max,ele);
        int i=1,j=max,ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(helper(mid,threshold,nums)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
}