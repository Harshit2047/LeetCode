class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       int x1=-1;
       int x2=-1;
       if(s1==s2) return true;
       for(int i=0;i<s1.size();i++){
           if(s1[i]!=s2[i]){
            if(x1==-1){
                x1=i;
                
            }
            else if(x2==-1){
                x2=i;
            }
            else return false;
           }
       } 
       if(x1==-1 || x2==-1) return false;
       cout<<x1<<" ";
       cout<<x2<<" ";
     swap(s1[x1],s1[x2]);
        if(s1==s2) return true;
        else return false;
    }
};