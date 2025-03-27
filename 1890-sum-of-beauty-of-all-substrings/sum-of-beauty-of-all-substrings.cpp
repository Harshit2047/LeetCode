class Solution {
public:
    int beautySum(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            vector<int> freq(26,0);
            for(int j=i;j<s.length();j++){
                freq[s[j]-'a']++;
                int mostF=INT_MIN;
                int leastF=INT_MAX;
                for(int k=0;k<freq.size();k++){
                    if(freq[k]!=0){
                        mostF=max(mostF,freq[k]);
                        leastF=min(leastF,freq[k]);
                    }
                }
               if(mostF!=INT_MIN && leastF!=INT_MAX) count+=mostF-leastF;
            }
        }
        return count;
    }
};