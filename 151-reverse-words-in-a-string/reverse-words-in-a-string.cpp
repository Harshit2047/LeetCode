class Solution {
public:
    string reverseWords(string s) {
        stringstream SS(s);
        string ans="";
        string temp;
        while(SS>>temp){
            reverse(temp.begin(),temp.end());
            ans+=temp;
            ans+=' ';
        }
        ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};