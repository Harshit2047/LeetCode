class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        vector<pair<int,int>> v;
        v.push_back({colors[0],0});
        for(int i=1;i<colors.length();i++){
            auto p=v.back();
            if(p.first==colors[i]){
                v.pop_back();
                if(neededTime[p.second]>neededTime[i]){
                    v.push_back({colors[i],p.second});
                }
                else{
                     v.push_back({colors[i],i});
                }
                ans+=min(neededTime[p.second],neededTime[i]);
            }
            else{
                v.push_back({colors[i],i});
            }
        }
        
        return ans;
    }
};