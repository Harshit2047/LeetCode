class Solution {
public:
    int minimumLength(string s) {
        map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto i:mp){
            int ch=i.first;
            int freq=i.second;
            while(freq>=3){
                freq=freq-2;
            }
            mp[ch]=freq;
        }
        int count=0;
        for(auto i:mp){
            count=count+i.second;
        }
        return count;
    }
};