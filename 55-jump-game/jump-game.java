class Solution {
    public boolean canJump(int[] nums) {
        int max=0,l=nums.length;
        for(int i=0;i<l;i++){
            max=Math.max(max,i+nums[i]);
            if(max>=l-1) return true;
            if(i>=max) return false;
        }
        return false;

    }
}