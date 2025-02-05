class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       int count = 0;
       for(int i=0;i<s1.size();++i){
           if(s1[i]!=s2[i]) count++;
       } 
        string x = s1;
        string y = s2;
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        if(x!=y) return false;
       if(count==0 || count==2) return true;

       return false;
    }
};