class Solution {
public:
    string helper(int n){
        if(n==0) return "1";
        string s=helper(n-1);
        int count=1;
        string temp="";
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]) count++;
            else{
                temp+=to_string(count)+s[i];
                count=1;
            }
        }
        temp+=to_string(count)+s[s.length()-1];

        return temp;
    }
    string countAndSay(int n) {
       return helper(n-1);
    }
};