class Solution {
public:
    string invert(string s){
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') s[i]='1';
            else if(s[i]=='1') s[i]='0';
        }
        return s;
    }
    void healper(string ans,int n,string &a){
        if(n==1){
            a=ans;
            cout<<a<<endl;
            return;
        }
        string inv=invert(ans);
        reverse(inv.begin(),inv.end());
        ans=ans+'1'+inv;
        
        n--;
        healper(ans,n,a);
    }
    char findKthBit(int n, int k) {
        string ans="0";
        string a="";
        healper(ans,n,a);
        return a[k-1];
    }
};