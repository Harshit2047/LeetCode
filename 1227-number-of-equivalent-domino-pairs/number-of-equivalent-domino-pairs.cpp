class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>,int> mp;
        for(auto i:dominoes){
            int mi=min(i[0],i[1]);
            int ma=max(i[0],i[1]);
            mp[{mi,ma}]++;
        }

        int ans=0;
        for(auto i:mp){
            int n=i.second;
            if(i.second>1) ans+=(n*(n-1))/2;
        }
        return ans;
    }
};