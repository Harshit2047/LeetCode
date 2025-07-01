class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        queue<pair<int,int>> q;
        q.push({k,0});
        vector<int> isVisited(n+1,INT_MAX);
        isVisited[k]=0;
        while(q.size()){
            int idx=q.front().first;
            int time=q.front().second;
            q.pop();
            for(int i=0;i<adj[idx].size();i++){
                int neighbor=adj[idx][i].first;
                int currTime=adj[idx][i].second;
                if(isVisited[neighbor]>time+currTime){
                    isVisited[neighbor]=time+currTime;
                    q.push({neighbor,time+currTime});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<isVisited.size();i++){
            ans=max(ans,isVisited[i]);
        }
        return ans==INT_MAX ? -1 : ans;
    }
};