class Solution {
public:
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]>='a' && s[i]<='z'){
                temp+=s[i];
            }
            else if(s[i]>='A' && s[i]<='Z'){
                temp+=s[i]+32;
            }
            else if(s[i]>='0' && s[i]<='9'){
                temp+=s[i];
            }

        }
        int i=0;
        int j=temp.size()-1;
        cout<<temp;
       
        while(i<j){
            if(temp[i]!=temp[j]) return false;
            i++;j--;
        }
        return true;
    }
};