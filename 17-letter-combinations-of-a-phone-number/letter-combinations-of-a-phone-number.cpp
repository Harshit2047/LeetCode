class Solution {
public:
    void helper(string digits,int idx,string ans,vector<string> &finalans,vector<string> &v){
        if(idx==digits.length()){
            if(ans.size()!=0)finalans.push_back(ans);
            return;
        }
        int i=digits[idx]-'0';
        string s=v[i];
        for(int i=0;i<s.length();i++){
            ans+=s[i];
            helper(digits,idx+1,ans,finalans,v);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> finalans;
        helper(digits,0,"",finalans,v);
        return finalans;
    }
};