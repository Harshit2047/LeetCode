class Solution {
public:
    int helper(string& s1, string& s2, int idx1, int idx2,
               vector<vector<int>>& dp) {
        if (idx1 == s1.size() || idx2 == s2.size())
            return 0;
        int count = 0;
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if (s1[idx1] == s2[idx2])
            count = 1 + helper(s1, s2, idx1 + 1, idx2 + 1, dp);
        else {
            count = max(helper(s1, s2, idx1 + 1, idx2, dp),
                        helper(s1, s2, idx1, idx2 + 1, dp));
        }
        return dp[idx1][idx2] = count;
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1));
        string s2 = s;
        reverse(s.begin(), s.end());
        for (int i = 0; i <s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                int count = 0;
                if (s2[i] == s[j])
                    count =((i>0) && (j>0))  ? 1 + dp[i-1][j-1] : 1;
                else {
                    int a=i>0 ? dp[i-1][j] : 0;
                    int b=j>0 ? dp[i][j-1] : 0;
                    count = max(a,b);
                }
                     dp[i][j] = count;
            }
        }
        return dp[s.size()-1][s.size()-1];
    }
};