class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for (auto i : s) {
            mp[i]++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (mp.find(t[i]) == mp.end())
                return false;
            else {
                mp[t[i]]--;
                if(mp[t[i]]==0) mp.erase(t[i]);
            }
        }
        return mp.size()==0;
    }
};