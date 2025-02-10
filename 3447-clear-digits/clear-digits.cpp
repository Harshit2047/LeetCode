class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                ans=ans.substr(0,ans.size()-1);
            }
            else ans+=s[i];
        }
        return ans;

        
    }
};