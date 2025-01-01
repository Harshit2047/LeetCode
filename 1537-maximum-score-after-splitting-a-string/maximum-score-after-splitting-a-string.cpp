class Solution {
public:
    int maxScore(string s) {
        int countOne=0;
        for(auto i:s){
            if(i=='1') countOne++;  // make count of all the ones present in string 
        }
        int countZero=0;
        int ans=INT_MIN;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1') countOne--; // then if 1 comes subtract it from countOne means now the we are on is come to left.
            else if(s[i]=='0') countZero++; // if 0 comes add 1 to countZero means the zero we are on is on the left 
            ans=max(ans,countOne+countZero); // find max of bot at each step 
        }
        return ans;
    }
};