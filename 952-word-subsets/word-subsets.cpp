class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        map<char,int>mp;
        for(auto i:words2){
            string s=i;
            map<char,int> temp;
            for(int j=0;j<s.length();j++){
                temp[s[j]]++;
            }
            for(auto k:temp){
                char c=k.first;
                int freq=k.second;
                mp[c]=max(mp[c],temp[c]);
            }
        }
        vector<string> ans;
        for(auto i:words1){
            bool mark=true;
            string s=i;
            map<char,int> temp;
            for(int j=0;j<s.length();j++){
                temp[s[j]]++;
            }
            for(auto i:mp){
                if(temp[i.first]<mp[i.first]){
                    mark=false;
                    break;
                }
            }
            if(mark) ans.push_back(s);

        }
        return ans;
    }
};