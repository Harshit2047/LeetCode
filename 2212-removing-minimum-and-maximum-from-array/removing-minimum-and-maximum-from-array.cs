public class Solution {

    public int MinimumDeletions(int[] nums) {

        int maxIdx = 0;
        int minIdx = 0;
        int n = nums.Length;

        for(int i = 0; i < n; i++) {
            if(nums[i] < nums[minIdx])
                minIdx = i;

            if(nums[i] > nums[maxIdx])
                maxIdx = i;
        }

        // CHANGE: always make minIdx the smaller index
        int left = Math.Min(minIdx, maxIdx);
        int right = Math.Max(minIdx, maxIdx);

        // CHANGE: calculate all 3 possibilities
        int fromFront = right + 1;
        int fromBack = n - left;
        int fromBoth = (left + 1) + (n - right);

        return Math.Min(fromFront, Math.Min(fromBack, fromBoth));
    }
}