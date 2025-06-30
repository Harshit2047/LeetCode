class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> outDegree(V);
        vector<vector<int>> adj(V);
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                outDegree[i]=graph[i].size();
            }
        }
        queue<int> q;
        for(int i=0;i<outDegree.size();i++){
            if(outDegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(q.size()){
            int idx=q.front();
            ans.push_back(idx);
            q.pop();
            for(int i=0;i<adj[idx].size();i++){
                int neighbor=adj[idx][i];
                outDegree[neighbor]--;
                if(outDegree[neighbor]==0) q.push(neighbor);
            }
        }
        while(q.size()){
            ans.push_back(q.front());
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};