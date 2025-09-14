class Solution {
public:
    string to_lower(string str){
        string ans="";
        for(int i=0;i<str.length();i++){
            ans+=tolower(str[i]);
        }
        return ans;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> v;
        unordered_set<string> st;
        unordered_map<string,int> dif;
        for(int i=0;i<wordlist.size();i++){
            string temp=wordlist[i];
            for(int j=0;j<temp.length();j++){
                temp[j]=tolower(temp[j]);
                if(temp[j]=='a' || temp[j]=='e' ||  temp[j]=='i' || temp[j]=='o' ||  temp[j]=='u') temp[j]='*';
            }
            if(dif.find(temp)==dif.end()) dif[temp]=i;
        }
        for(auto i:wordlist) st.insert(i);
        unordered_map<string,int> mp;
        for(int i=0;i<wordlist.size();i++){
            if(mp.find(to_lower(wordlist[i]))==mp.end()){
                mp[to_lower(wordlist[i])]=i;
            }
        }
        for(auto x:queries){
            string ans="";
            if(st.find(x)!=st.end()) ans=x;
            else if(mp.find(to_lower(x))!=mp.end()){
                ans=wordlist[mp[to_lower(x)]];
            }
            else{
                for(int j=0;j<x.length();j++){
                x[j]=tolower(x[j]);
                if(x[j]=='a' || x[j]=='e' ||  x[j]=='i' || x[j]=='o' ||  x[j]=='u') x[j]='*';
                }
                if(dif.find(x)!=dif.end()) ans=wordlist[dif[x]];
            }
            v.push_back(ans);
        }
        return v;
    }
};