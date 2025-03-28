class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        if(i>=j) return true;
        if(s[i]==s[j]) return isPalindrome(s,i+1,j-1);
        else return false;
    }
    string longestPalindrome(string s) {
        int maxLen=0;
        int start=0;
        int end=0;
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(maxLen<j-i+1 && isPalindrome(s,i,j)){
                    maxLen=j-i+1;
                    start=i;
                    end=j;
                }
                
            }
        }
        return s.substr(start,end-start+1);
    }
};