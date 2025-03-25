class Solution {
public:
    bool isPalendrome(string s){
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(string s,vector<vector<string>> &finalans,vector<string> ans){
        if(s==""){
            finalans.push_back(ans);
            return;
        }
        for(int i=0;i<s.length();i++){
            string temp=s.substr(0,i+1);
            string left=s.substr(i+1);;
            if(isPalendrome(temp)){
                ans.push_back(temp);
                helper(left,finalans,ans);
                ans.pop_back();
            } 
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> finalans;
        vector<string> ans;
        helper(s,finalans,ans);
        return finalans;
    }
};