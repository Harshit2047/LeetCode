class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        bool Z=false;
        bool sign=false;
        bool N=false;
        bool space=false;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0' && Z==false){
                sign=true;
                space=true;
                continue;
            }
            else if(isdigit(s[i])){
                ans=ans*10+(s[i]-'0');
                Z=true;
                sign=true;
                space =true;
                if(ans>INT_MAX && !N) return INT_MAX;
                else if(-ans<INT_MIN && N) return INT_MIN;
            }
            else if(s[i]=='+' && sign==false){
                sign=true;
                space=true;
            }
            else if(s[i]=='-' && sign==false){
                sign=true;
                space=true;
                N=true;
            }
            else if(s[i]==' ' && space==false){
                continue;
            }
            else break;
        }
        if(N) return -ans;
        else return ans;
    }
};