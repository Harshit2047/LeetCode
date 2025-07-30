class Solution {
public:
    int totalFruit(vector<int>& s) {
        int i=0;
        int j=0;
        int ans=INT_MIN;
        unordered_map<int,int> mp;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()>2){
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                 i++;
            }
            ans=max(j-i+1,ans);
            j++;
        }
        return ans;
    }
};