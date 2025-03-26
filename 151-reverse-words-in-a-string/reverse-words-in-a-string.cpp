class Solution {
public:
    string reverseWords(string s) {
        int i=s.length()-1;
        string ans="";
        while(i>=0){
            string chunk=" ";
            while(i>=0 && s[i]!=' '){
                chunk+=s[i];
                i--;
            }
            string temp=" ";
            reverse(chunk.begin(),chunk.end());
            if(chunk!=temp)ans+=chunk;
            i--;
        }
        ans.pop_back();
        return ans;
    }
};