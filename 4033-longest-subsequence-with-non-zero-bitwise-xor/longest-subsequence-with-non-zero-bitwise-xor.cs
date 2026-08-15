public class Solution {
    public int LongestSubsequence(int[] nums) {
        bool allZero=true;
        int XOR=0;
        int n=nums.Length;
        for(int i=0;i<nums.Length;i++){
            if(nums[i]!=0) allZero=false;
            XOR^=nums[i];
        }
        if(allZero==true) return 0;
        if(XOR!=0) return n;
        return n-1;
    }
}