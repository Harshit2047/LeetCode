class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int i = 0, j = 0;
        long long ans = 0, sum = 0;
        while (j < nums.size()) {
            sum += nums[j];
            long long len = j - i + 1;
            while (sum * len >= k) {
                sum -= nums[i];
                i++;
                len = j - i + 1;
            }
            ans += (j - i + 1);
            j++;
        }
        return ans;
    }
};
