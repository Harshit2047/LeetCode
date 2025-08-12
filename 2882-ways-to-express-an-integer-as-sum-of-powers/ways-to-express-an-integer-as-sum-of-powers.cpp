class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> powers;
    vector<vector<int>> dp;

    int numberOfWays(int n, int x) {
        // Precompute powers
        for (int i = 1; ; i++) {
            long long p = 1;
            for (int j = 0; j < x; j++) p *= i;
            if (p > n) break;
            powers.push_back(p);
        }

        dp.assign(powers.size(), vector<int>(n + 1, -1));
        return dfs(0, n);
    }

    int dfs(int idx, int remaining) {
        if (remaining == 0) return 1;
        if (idx >= powers.size() || remaining < 0) return 0;

        if (dp[idx][remaining] != -1) return dp[idx][remaining];

        long long take = dfs(idx + 1, remaining - powers[idx]);
        long long skip = dfs(idx + 1, remaining);

        return dp[idx][remaining] = (take + skip) % MOD;
    }
};
