class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;
        vector<int> freq(256, 0);
        int ans = 0;

        while(i < s.length()){
            char ch = s[i];
            freq[ch]++;
            while(freq[ch] > 1){
                freq[s[j]]--;
                j++;
            }

            ans = max(ans, i - j + 1);
            i++;
        }

        return ans;
    }
};