class Solution {
public:
    int helper(string& s1, string& s2, int idx1, int idx2,
               vector<vector<int>>& dp) {
        if (idx1 == s1.size() || idx2 == s2.size())
            return 0;
        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        int count = 0;
        if (s1[idx1] == s2[idx2])
            count = 1 + helper(s1, s2, idx1 + 1, idx2 + 1, dp);
        else {
            count = max(helper(s1, s2, idx1 + 1, idx2, dp),
                        helper(s1, s2, idx1, idx2 + 1, dp));
        }
        return dp[idx1][idx2] = count;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));

        for (int i = 0; i < word1.size(); i++) {
            for (int j = 0; j < word2.size(); j++) {
                int count = 0;
                if (word1[i] == word2[j]){
                    int call= (i>0 && j>0) ? dp[i-1][j-1] : 0;
                    count = 1+call;
                }
                else {
                    int a= (i>0) ? dp[i-1][j] : 0;
                    int b= (j>0) ? dp[i][j-1] : 0;

                    count = max(a,b);
                }
                 dp[i][j] = count;
            }
        }

        int SLCS = dp[word1.size()-1][word2.size()-1];
        return ((word1.size() + word2.size()) - SLCS * 2);
    }
};