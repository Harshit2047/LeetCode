class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>());
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int> costArr(n+1,INT_MAX);
        costArr[k]=0;
        queue<pair<int,int>> q;
        q.push({k,0});
        while(q.size()){
            auto i=q.front();
            q.pop();
            int temp=i.first;
            int cost=i.second;
            if(costArr[temp]<i.second) continue;
            for(int i=0;i<adj[temp].size();i++){
                int neighbor=adj[temp][i].first;
                int currCost=adj[temp][i].second;
                int total=cost+currCost;
                if(costArr[neighbor]>total){
                    costArr[neighbor]=total;
                    q.push({neighbor,total});
                }
            }
        } 
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,costArr[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};