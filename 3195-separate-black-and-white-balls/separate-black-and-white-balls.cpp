class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int i=0;
        int j=0;
        while(j<s.size()){
            while(j<s.size() && s[j]!='0'){
                j++;
            }
            if(s[i]=='1' && s[j]=='0'){
                swap(s[i],s[j]);
                ans=ans+j-i;
                i++;
            }
            else{
                i++;j++;
            }
        }
        return ans;
    }
};