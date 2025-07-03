class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.length()<=k){
            string temp="";
            for(int i=0;i<s.length();i++){
                temp+=char((s[i]+1));
                
            }
            cout<<temp<<endl;;
            s+=temp;
        }
        return s[k-1];
    }
};