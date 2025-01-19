class Solution {
public:
    bool helper(string& s, string& p, int idx1, int idx2, vector<vector<int>>& memo) {
        // Base cases
        if (idx1 < 0 && idx2 < 0) return true; // Both strings are exhausted
        if (idx2 < 0) return false;           // Pattern exhausted but string is not
        if (idx1 < 0) {
            // String exhausted but pattern still remains
            // Check if the remaining pattern is all '*'
            for (int i = 0; i <= idx2; i++) {
                if (p[i] != '*') return false;
            }
            return true;
        }

        // Check memoization
        if (memo[idx1][idx2] != -1) return memo[idx1][idx2];

        bool result = false;

        // If characters match or pattern character is '?'
        if (s[idx1] == p[idx2] || p[idx2] == '?') {
            result = helper(s, p, idx1 - 1, idx2 - 1, memo);
        } 
        // If pattern character is '*'
        else if (p[idx2] == '*') {
     result = helper(s, p, idx1 - 1, idx2, memo) || helper(s, p, idx1, idx2 - 1, memo);
        }

        // Store the result in memoization table
        return memo[idx1][idx2] = result;
    }

    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> memo(n, vector<int>(m, -1)); // Memoization table
        return helper(s, p, n - 1, m - 1, memo);
    }
};
