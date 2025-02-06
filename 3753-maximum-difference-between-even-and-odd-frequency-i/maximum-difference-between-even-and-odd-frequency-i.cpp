class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for (char ele : s) {
            mp[ele]++;
        }

        int even = INT_MAX, odd = INT_MIN;
        for (auto x : mp) {
            int freq = x.second;
            if (freq % 2 == 0) {
                even = min(even, freq);
            } 
            else {
                odd = max(odd, freq);
            }
        }
        if(odd==INT_MAX || even==INT_MIN) return -1;
        return odd - even;
    }
};