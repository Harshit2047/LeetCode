class Solution {
public:
    bool helper(string& s1, string& s2, string& s3, int idx1, int idx2, int idx3, vector<vector<vector<int>>>& dp) {
        if (idx1 < 0 && idx2 < 0 && idx3 < 0) return true; 
        if (idx1 >= 0 && idx2 >= 0 && idx3 >= 0 && dp[idx1][idx2][idx3] != -1) return dp[idx1][idx2][idx3];
        
        if (idx1 >= 0 && idx2 >= 0 && s1[idx1] == s3[idx3] && s2[idx2] == s3[idx3]) {
            return dp[idx1][idx2][idx3] = (helper(s1, s2, s3, idx1 - 1, idx2, idx3 - 1, dp) || 
                                           helper(s1, s2, s3, idx1, idx2 - 1, idx3 - 1, dp));
        }
        else if (idx1 >= 0 && s1[idx1] == s3[idx3]) {
            return  helper(s1, s2, s3, idx1 - 1, idx2, idx3 - 1, dp);
        }
        else if (idx2 >= 0 && s2[idx2] == s3[idx3]) {
            return  helper(s1, s2, s3, idx1, idx2 - 1, idx3 - 1, dp);
        }
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int idx1 = s1.length();
        int idx2 = s2.length();
        int idx3 = s3.length();
        if (idx1 + idx2 != idx3) return false;
        vector<vector<vector<int>>> dp(idx1 + 1, vector<vector<int>>(idx2 + 1, vector<int>(idx3 + 1, -1)));
        return helper(s1, s2, s3, idx1 - 1, idx2 - 1, idx3 - 1, dp);
    }
};
