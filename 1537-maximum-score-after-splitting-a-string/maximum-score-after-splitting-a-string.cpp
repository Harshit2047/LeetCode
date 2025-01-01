class Solution {
public:
    int maxScore(string s) {
        int countOne=0;
        for(auto i:s){
            if(i=='1') countOne++;
        }
        int countZero=0;
        int ans=INT_MIN;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1') countOne--;
            else if(s[i]=='0') countZero++;
            ans=max(ans,countOne+countZero);
        }
        return ans;
    }
};