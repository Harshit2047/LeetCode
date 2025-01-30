class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),0));
        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                int p = (i >= 1 && j >=1) ?  dp[i - 1][j - 1] : 0;
                int q = (i >= 1) ? dp[i - 1][j] : 0;
                int r = (j >= 1) ? dp[i][j - 1] : 0;
                if (text1[i] == text2[j])
                    dp[i][j] = 1+ p;
                else
                    dp[i][j] = max(q, r);
            }
            
        }
        int ans=INT_MIN;
         for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                ans=max(ans,dp[i][j]);
            }
            
        }
         return ans;
    }
};