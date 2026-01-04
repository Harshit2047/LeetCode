class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int maxNumber = 0;
        for (int x : nums) maxNumber = max(maxNumber, x);

        vector<int> cnt(maxNumber + 1, 0), sum(maxNumber + 1, 0);

        for (int i = 1; i <= maxNumber; i++) {
            for (int j = i; j <= maxNumber; j += i) {
                cnt[j]++;
                sum[j] += i;
            }
        }

        int ans = 0;
        for (int x : nums) {
            if (cnt[x] == 4) ans += sum[x];
        }
        return ans;
    }
};
