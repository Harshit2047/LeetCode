class Solution {
public:
    void dfs(int start,vector<vector<int>> &adjList,vector<bool> &isVisted,int &e,int &v){
        isVisted[start]=true;
        v++;
        e+=adjList[start].size();
        for(int i=0;i<adjList[start].size();i++){
            if(isVisted[adjList[start][i]]==false){
                dfs(adjList[start][i],adjList,isVisted,e,v);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> isVisted(n,false);
        vector<vector<int>> adjList(n);
        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(isVisted[i]==false){
                int e=0;
                int v=0;
                dfs(i,adjList,isVisted,e,v);
                if((v*(v-1))==e) ans++;
            }
        }
        return ans;
    }
};