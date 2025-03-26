class Solution {
public:
    bool rotateString(string s, string goal) {
        int size=s.length();
        while(size--){
            char last=s[s.size()-1];
            s.pop_back();
            s=last+s;
            if(s==goal) return true;
        }        
        return false;
    }
};