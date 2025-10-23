class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length()!=2){
            string temp="";
            for(int i=0;i<s.length()-1;i++){
                int val=(s[i]-'0'+s[i+1]-'0')%10;
                temp+=val+'0';
            }
            s=temp;
        }
        if(s[0]==s[1]) return true;
        else return false;
    }
};