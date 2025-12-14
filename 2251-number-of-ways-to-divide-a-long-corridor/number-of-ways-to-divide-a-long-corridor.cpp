class Solution {
public:
    const int M=1e9+7;
    int numberOfWays(string s) {
        vector<int> idx;
        for(int i=0;i<s.length();i++){
            if(s[i]=='S'){
                idx.push_back(i);
            }
        }

        if(idx.size()==0 || idx.size()==1 || idx.size()%2!=0) return 0;
        if(idx.size()==2) return 1;

        int prevIdx=1;
        int nextIdx=2;
        long long ans=1;
        while(nextIdx<idx.size()){
            ans = (ans * (idx[nextIdx] - idx[prevIdx])) % M;
            prevIdx+=2;
            nextIdx+=2;
        }
        return (int)ans;
    }
};