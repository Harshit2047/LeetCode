class Solution {
public:
    bool helper(vector<int> &stones, int idx, int reach, unordered_map<int, int> &mp, unordered_map<string, bool> &dp) {
        if (idx == stones.size() - 1) return true;

        string key = to_string(idx) + "_" + to_string(reach);
        if (dp.find(key) != dp.end()) return dp[key];

        int start = reach - 1;
        int end = reach + 1;
        for (int i = start; i <= end; i++) {
            if (i <= 0) continue;
            int nextPos = stones[idx] + i;
            if (mp.find(nextPos) != mp.end()) {
                if (helper(stones, mp[nextPos], i, mp, dp)) {
                    return dp[key] = true;  
                }
            }
        }

        return dp[key] = false;  
    }

    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false; 

        unordered_map<int, int> mp;
        unordered_map<string, bool> dp;  
        for (int i = 0; i < stones.size(); i++) {
            mp[stones[i]] = i;
        }
        return helper(stones, 1, 1, mp, dp);  
    }
};
