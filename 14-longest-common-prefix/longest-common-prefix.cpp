class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[strs.size()-1];
        if(first.length()==0) return "";
        if(last.length()==0) return "";
        string ans="";
        int i=0;
        if(first==last) return first;
        while(first[i]==last[i]){
            ans+=first[i];
            i++;
        }
        return ans;
    }
};