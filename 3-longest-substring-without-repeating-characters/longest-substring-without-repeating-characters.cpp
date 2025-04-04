class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        unordered_map<char,int> mp;
        int maxL=0;
        while(j<s.length()){
            mp[s[j]]++;
            if(mp[s[j]]==1) maxL=max(maxL,j-i+1);
            else{
                while(mp[s[j]]!=1){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return maxL;
    }
};