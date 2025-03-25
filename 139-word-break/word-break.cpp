class Solution {
public:
    bool helper(string s,unordered_set<string> &st,unordered_map<string,bool> &mp){
        if(s=="") return true;
        if(mp.find(s)!=mp.end()) return mp[s];
        for(int i=0;i<s.size();i++){
            string temp=s.substr(0,i+1);
            if(st.find(temp)!=st.end()){
                string left=s.substr(i+1);
                if(helper(left,st,mp)) return mp[s]=true;
            }
        }
        return mp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        unordered_map<string,bool> mp;
        for(auto i:wordDict){
            st.insert(i);
        }
        return helper(s,st,mp);
    }
};