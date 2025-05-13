class Solution {
public:
    int mod=1e9+7;
    int lengthAfterTransformations(string s, int t) {
       vector<int> v(26,0);
       for(int i=0;i<s.length();i++){
            v[s[i]-'a']++;
       }
       for(int i=0;i<t;i++){
        vector<int> temp(26,0);
        for(int i=0;i<26;i++){
            char ch=i+'a';
            int freq=v[i];
            if(ch!='z'){
                temp[ch-'a'+1]=(temp[ch-'a'+1]+freq)%mod;
            }
            else{
                temp['a'-'a']=(temp['a'-'a']+freq)%mod;;
                temp['b'-'a']=(temp['b'-'a']+freq)%mod;;
            }
        }
        v.assign(temp.begin(),temp.end());
       }
       int ans=0;
       for(auto i:v ){
        ans=(ans+i)%mod;
       }
       return ans;
    }
};