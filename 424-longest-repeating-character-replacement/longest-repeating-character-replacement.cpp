class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0;
        int j=0;
        int ans=0;
        int maxF=0;
        unordered_map<char,int> mp;
        while(j<s.length()){
            mp[s[j]]++;
            maxF=max(maxF,mp[s[j]]);
            if((j-i+1)-maxF<=k) ans=max(ans,j-i+1);
            while((j-i+1)-maxF>k){
                mp[s[i]]--;
                // for(auto i:mp){
                //     maxF=max(maxF,i.second);     // this loop is unnassary but hard to understand why 
                // }
                i++;
            } 
            j++;
        }
        return ans;
    }
};