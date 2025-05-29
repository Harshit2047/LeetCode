class Solution {
public:
    static bool compareByLength(const string &a, const string &b) {
        return a.length() < b.length(); 
    }

    bool help(string &shorter, string &longer) {
        if (longer.length() - shorter.length() != 1) return false;
        int i = 0, j = 0;
        while (i < shorter.size() && j < longer.size()) {
            if (shorter[i] == longer[j]) {
                i++, j++;
            } else {
                j++;
            }
        }
        return i == shorter.size();
    }

    int helper(vector<string> &words, int idx, int prevIdx,vector<vector<int>> &dp) {
        if (idx == words.size()) return 0;
        if(dp[idx][prevIdx]!=-1) return dp[idx][prevIdx];
        int take = 0;
        if (words[prevIdx].size() + 1 == words[idx].size() && help(words[prevIdx], words[idx])) {
            take = 1 + helper(words, idx + 1, idx,dp);
        }
        int nottake = helper(words, idx + 1, prevIdx,dp);
        return dp[idx][prevIdx]=max(take, nottake);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), compareByLength);
        int maxLen = 1;
        vector<vector<int>> dp(words.size(),vector<int>(words.size(),-1));
        for (int i = 0; i < words.size(); i++) {
            maxLen = max(maxLen, 1 + helper(words, i + 1, i,dp));
        }
        return maxLen;
    }
};
