class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        int start = 0;
        int end = 0;
        int temp = INT_MIN;
        for (int k = 0; k < s.length(); k++) {
            int i = 0;
            int j = k;

            while (j < s.length()) {
                if (i == j) {
                    dp[i][j] = 1;
                    if (temp < j - i) {
                        temp = j - i;
                        start = i;
                        end = j;
                    }

                } else if (i == j - 1) {
                    if (s[i] == s[j]) {
                        dp[i][j] = 1;
                        if (temp < j - i) {
                            temp = j - i;
                            start = i;
                            end = j;
                        }
                    }
                } else {
                    if (s[i] == s[j]) {
                        if (dp[i + 1][j - 1] == 1) {
                            dp[i][j] = 1;
                            if (temp < j - i) {
                                temp = j - i;
                                start = i;
                                end = j;
                            }
                        }
                    }
                }

                i++;
                j++;
            }
        }
        cout << start << " " << end;
        string sub = s.substr(start, temp+1);
        return sub;
    }
};