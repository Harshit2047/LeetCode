class Solution {
public:
    // int helper(string &t1,string &t2,int idx1,int
    // idx2,vector<vector<int>>&dp){
    //     if(idx1==t1.length()|| idx2==t2.length()) return 0;
    //     int count1=0;
    //     int count2=0;
    //     if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    //     if(t1[idx1]==t2[idx2])  count1=1+helper(t1,t2,idx1+1,idx2+1);
    //     if(t1[idx1]!=t2[idx2])
    //     count2=max(helper(t1,t2,idx1+1,idx2),helper(t1,t2,idx1,idx2+1));
    //     return count1+count2;
    // }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(2, vector<int>(text2.size()));
        for (int i = 0; i < text1.size(); i++) {
            for (int j = 0; j < text2.size(); j++) {
                int p = (i >= 1 && j > 0) ?  dp[1 - 1][j - 1] : 0;
                int q = (i >= 1) ? dp[1 - 1][j] : 0;
                int r = (j >= 1) ? dp[1][j - 1] : 0;
                if (text1[i] == text2[j])
                    dp[1][j] = 1+ p;
                else
                    dp[1][j] = max(q, r);
            }
            for(int x=0;x<text2.size();x++) dp[0][x]=dp[1][x];
        }
        return dp[1][text2.size() - 1];
    }
};