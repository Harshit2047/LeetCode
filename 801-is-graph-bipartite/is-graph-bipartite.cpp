class Solution {
public:
    bool helper(vector<vector<int>> &graph,vector<int> &isVisited,int i){
        queue<pair<int,int>> q;
        q.push({i,-1});
        while(q.size()){
            int idx=q.front().first;
            int color=q.front().second;
            q.pop();
            for(int i=0;i<graph[idx].size();i++){
                if(isVisited[graph[idx][i]]==-1){
                    int c=color^1;
                    isVisited[graph[idx][i]]=c;
                    q.push({graph[idx][i],c});
                }
                else{
                    if(color==isVisited[graph[idx][i]]) return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> isVisited(n,-1);
        for(int i=0;i<n;i++){
            if(isVisited[i]==-1){
                if(helper(graph,isVisited,i)==false){
                    return false;
                }
            }
        }
        return true;;
    }
};