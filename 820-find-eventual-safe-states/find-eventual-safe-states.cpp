class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> inD(graph.size(),0);
        vector<int> ans;
        vector<vector<int>> adj(graph.size(),vector<int>());
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                inD[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<inD.size();i++){
            if(inD[i]==0) q.push(i);
        }
        while(q.size()){
            int temp=q.front();
            q.pop();
            ans.push_back(temp);
            for(int i=0;i<adj[temp].size();i++){
                int neighbor=adj[temp][i];
                inD[neighbor]--;
                if(inD[neighbor]==0) q.push(neighbor);
            }

        }
       
    sort(ans.begin(),ans.end());
    return ans;

    }
};